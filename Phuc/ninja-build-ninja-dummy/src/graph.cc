// Copyright 2011 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "graph.h"

#include <algorithm>
#include <deque>
#include <assert.h>
#include <stdio.h>

#include "build_log.h"
#include "debug_flags.h"
#include "depfile_parser.h"
#include "deps_log.h"
#include "disk_interface.h"
#include "manifest_parser.h"
#include "metrics.h"
#include "state.h"
#include "util.h"

using namespace std;

bool Node::Stat(DiskInterface* disk_interface, string* err) {
  mtime_ = disk_interface->Stat(path_, err);
  if (mtime_ == -1) {
    return false;
  }
  exists_ = (mtime_ != 0) ? ExistenceStatusExists : ExistenceStatusMissing;
  return true;
}

void Node::UpdatePhonyMtime(TimeStamp mtime) {
  if (!exists()) {
    mtime_ = std::max(mtime_, mtime);
  }
}

bool DependencyScan::RecomputeDirty(Node* initial_node,
                                    std::vector<Node*>* validation_nodes,
                                    string* err) {
  std::vector<Node*> stack;
  std::vector<Node*> new_validation_nodes;

  std::deque<Node*> nodes(1, initial_node);

  // RecomputeNodeDirty might return new validation nodes that need to be
  // checked for dirty state, keep a queue of nodes to visit.
  while (!nodes.empty()) {
    Node* node = nodes.front();
    nodes.pop_front();

    stack.clear();
    new_validation_nodes.clear();

    if (!RecomputeNodeDirty(node, &stack, &new_validation_nodes, err))
      return false;
    nodes.insert(nodes.end(), new_validation_nodes.begin(),
                              new_validation_nodes.end());
    if (!new_validation_nodes.empty()) {
      //assert(validation_nodes &&
      //     "validations require RecomputeDirty to be called with validation_nodes");
      // validation_nodes->insert(validation_nodes->end(),
      //                      new_validation_nodes.begin(),
      //                      new_validation_nodes.end());
    }
  }

  return true;
}

bool DependencyScan::RecomputeNodeDirty(Node* node, std::vector<Node*>* stack,
                                        std::vector<Node*>* validation_nodes,
                                        string* err) {
  return true;
}

bool DependencyScan::VerifyDAG(Node* node, vector<Node*>* stack, string* err) {
  Edge* edge = node->in_edge();
  //assert(edge != NULL);

  // If we have no temporary mark on the edge then we do not yet have a cycle.
  if (edge->mark_ != Edge::VisitInStack)
    return true;

  // We have this edge earlier in the call stack.  Find it.
  vector<Node*>::iterator start = stack->begin();
  while (start != stack->end() && (*start)->in_edge() != edge)
    ++start;
  //assert(start != stack->end());

  // Make the cycle clear by reporting its start as the node at its end
  // instead of some other output of the starting edge.  For example,
  // running 'ninja b' on
  //   build a b: cat c
  //   build c: cat a
  // should report a -> c -> a instead of b -> c -> a.
  *start = node;

  // Construct the error message rejecting the cycle.
  *err = "dependency cycle: ";
  // for (vector<Node*>::const_iterator i = start; i != stack->end(); ++i) {
  //   err->append((*i)->path());
  //   err->append(" -> ");
  // }
  // err->append((*start)->path());

  if ((start + 1) == stack->end() && edge->maybe_phonycycle_diagnostic()) {
    // The manifest parser would have filtered out the self-referencing
    // input if it were not configured to allow the error.
    err->append(" [-w phonycycle=err]");
  }

  return false;
}

bool DependencyScan::RecomputeOutputsDirty(Edge* edge, Node* most_recent_input,
                                           bool* outputs_dirty, string* err) {
  // string command = edge->EvaluateCommand(true);
  // for (vector<Node*>::iterator o = edge->outputs_.begin();
  //      o != edge->outputs_.end(); ++o) {
  //   if (RecomputeOutputDirty(edge, most_recent_input, command, *o)) {
  //     *outputs_dirty = true;
  //     return true;
  //   }
  // }
  return true;
}

bool DependencyScan::RecomputeOutputDirty(const Edge* edge,
                                          const Node* most_recent_input,
                                          const string& command,
                                          Node* output) {
  if (edge->is_phony()) {
    // Phony edges don't write any output.  Outputs are only dirty if
    // there are no inputs and we're missing the output.
    if (edge->inputs_.empty() && !output->exists()) {
      // explanations_.Record(
      //     output, "output %s of phony edge with no inputs doesn't exist",
      //     output->path().c_str());
      return true;
    }

    // Update the mtime with the newest input. Dependents can thus call mtime()
    // on the fake node and get the latest mtime of the dependencies
    if (most_recent_input) {
      output->UpdatePhonyMtime(most_recent_input->mtime());
    }

    // Phony edges are clean, nothing to do
    return false;
  }

  // Dirty if we're missing the output.
  if (!output->exists()) {
    explanations_.Record(output, "output %s doesn't exist",
                         output->path().c_str());
    return true;
  }
    return true;
}


bool DependencyScan::LoadDyndeps(Node* node, string* err) const {
  return dyndep_loader_.LoadDyndeps(node, err);
}

bool DependencyScan::LoadDyndeps(Node* node, DyndepFile* ddf,
                                 string* err) const {
  return dyndep_loader_.LoadDyndeps(node, ddf, err);
}

bool Edge::AllInputsReady() const {
  for (vector<Node*>::const_iterator i = inputs_.begin();
       i != inputs_.end(); ++i) {
    if ((*i)->in_edge() && !(*i)->in_edge()->outputs_ready())
      return false;
  }
  return true;
}

/// An Env for an Edge, providing $in and $out.
struct EdgeEnv : public Env {
  enum EscapeKind { kShellEscape, kDoNotEscape };

  EdgeEnv(const Edge* const edge, const EscapeKind escape)
      : edge_(edge), escape_in_out_(escape), recursive_(false) {}
  virtual string LookupVariable(const string& var);

  /// Given a span of Nodes, construct a list of paths suitable for a command
  /// line.
  std::string MakePathList(const Node* const* span, size_t size, char sep) const;

 private:
  std::vector<std::string> lookups_;
  const Edge* const edge_;
  EscapeKind escape_in_out_;
  bool recursive_;
};

string EdgeEnv::LookupVariable(const string& var) {
  if (var == "in" || var == "in_newline") {
    int explicit_deps_count =
        static_cast<int>(edge_->inputs_.size() - edge_->implicit_deps_ -
                         edge_->order_only_deps_);
    return MakePathList(edge_->inputs_.data(), explicit_deps_count,
                        var == "in" ? ' ' : '\n');
  } else if (var == "out") {
    int explicit_outs_count =
        static_cast<int>(edge_->outputs_.size() - edge_->implicit_outs_);
    return MakePathList(&edge_->outputs_[0], explicit_outs_count, ' ');
  }

  // Technical note about the lookups_ vector.
  //
  // This is used to detect cycles during recursive variable expansion
  // which can be seen as a graph traversal problem. Consider the following
  // example:
  //
  //    rule something
  //      command = $foo $foo $var1
  //      var1 = $var2
  //      var2 = $var3
  //      var3 = $var1
  //      foo = FOO
  //
  // Each variable definition can be seen as a node in a graph that looks
  // like the following:
  //
  //   command --> foo
  //      |
  //      v
  //    var1 <-----.
  //      |        |
  //      v        |
  //    var2 ---> var3
  //
  // The lookups_ vector is used as a stack of visited nodes/variables
  // during recursive expansion. Entering a node adds an item to the
  // stack, leaving the node removes it.
  //
  // The recursive_ flag is used as a small performance optimization
  // to never record the starting node in the stack when beginning a new
  // expansion, since in most cases, expansions are not recursive
  // at all.
  //
  if (recursive_) {
    auto it = std::find(lookups_.begin(), lookups_.end(), var);
    if (it != lookups_.end()) {
      std::string cycle;
      for (; it != lookups_.end(); ++it)
        cycle.append(*it + " -> ");
      cycle.append(var);
      Fatal(("cycle in rule variables: " + cycle).c_str());
    }
  }

  // See notes on BindingEnv::LookupWithFallback.
  const EvalString* eval = edge_->rule_->GetBinding(var);
  bool record_varname = recursive_ && eval;
  if (record_varname)
    lookups_.push_back(var);

  // In practice, variables defined on rules never use another rule variable.
  // For performance, only start checking for cycles after the first lookup.
  recursive_ = true;
  std::string result = edge_->env_->LookupWithFallback(var, eval, this);
  if (record_varname)
    lookups_.pop_back();
  return result;
}

std::string EdgeEnv::MakePathList(const Node* const* const span,
                                  const size_t size, const char sep) const {
  string result;
  for (const Node* const* i = span; i != span + size; ++i) {
    if (!result.empty())
      result.push_back(sep);
    const string& path = (*i)->PathDecanonicalized();
    if (escape_in_out_ == kShellEscape) {
#ifdef _WIN32
      GetWin32EscapedString(path, &result);
#else
      GetShellEscapedString(path, &result);
#endif
    } else {
      result.append(path);
    }
  }
  return result;
}

std::string Edge::EvaluateCommand(const bool incl_rsp_file) const {
  string command = GetBinding("command");
  if (incl_rsp_file) {
    string rspfile_content = GetBinding("rspfile_content");
    if (!rspfile_content.empty())
      command += ";rspfile=" + rspfile_content;
  }
  return command;
}

std::string Edge::GetBinding(const std::string& key) const {
  EdgeEnv env(this, EdgeEnv::kShellEscape);
  return env.LookupVariable(key);
}

bool Edge::GetBindingBool(const string& key) const {
  return !GetBinding(key).empty();
}

string Edge::GetUnescapedDepfile() const {
  EdgeEnv env(this, EdgeEnv::kDoNotEscape);
  return env.LookupVariable("depfile");
}

string Edge::GetUnescapedDyndep() const {
  EdgeEnv env(this, EdgeEnv::kDoNotEscape);
  return env.LookupVariable("dyndep");
}

std::string Edge::GetUnescapedRspfile() const {
  EdgeEnv env(this, EdgeEnv::kDoNotEscape);
  return env.LookupVariable("rspfile");
}

void Edge::Dump(const char* prefix) const {
  printf("%s[ ", prefix);
  for (vector<Node*>::const_iterator i = inputs_.begin();
       i != inputs_.end() && *i != NULL; ++i) {
    printf("%s ", (*i)->path().c_str());
  }
  printf("--%s-> ", rule_->name().c_str());
  for (vector<Node*>::const_iterator i = outputs_.begin();
       i != outputs_.end() && *i != NULL; ++i) {
    printf("%s ", (*i)->path().c_str());
  }
  if (!validations_.empty()) {
    printf(" validations ");
    for (std::vector<Node*>::const_iterator i = validations_.begin();
         i != validations_.end() && *i != NULL; ++i) {
      printf("%s ", (*i)->path().c_str());
    }
  }
  if (pool_) {
    if (!pool_->name().empty()) {
      printf("(in pool '%s')", pool_->name().c_str());
    }
  } else {
    printf("(null pool?)");
  }
  printf("] 0x%p\n", this);
}

bool Edge::is_phony() const {
  return rule_->IsPhony();
}

bool Edge::use_console() const {
  return pool() == &State::kConsolePool;
}

bool Edge::maybe_phonycycle_diagnostic() const {
  // CMake 2.8.12.x and 3.0.x produced self-referencing phony rules
  // of the form "build a: phony ... a ...".   Restrict our
  // "phonycycle" diagnostic option to the form it used.
  return is_phony() && outputs_.size() == 1 && implicit_outs_ == 0 &&
      implicit_deps_ == 0;
}

// static
string Node::PathDecanonicalized(const string& path, uint64_t slash_bits) {
  string result = path;
#ifdef _WIN32
  uint64_t mask = 1;
  for (char* c = &result[0]; (c = strchr(c, '/')) != NULL;) {
    if (slash_bits & mask)
      *c = '\\';
    c++;
    mask <<= 1;
  }
#endif
  return result;
}

void Node::Dump(const char* prefix) const {
  printf("%s <%s 0x%p> mtime: %" PRId64 "%s, (:%s), ",
         prefix, path().c_str(), this,
         mtime(), exists() ? "" : " (:missing)",
         dirty() ? " dirty" : " clean");
  if (in_edge()) {
    in_edge()->Dump("in-edge: ");
  } else {
    printf("no in-edge\n");
  }
  printf(" out edges:\n");
  for (vector<Edge*>::const_iterator e = out_edges().begin();
       e != out_edges().end() && *e != NULL; ++e) {
    (*e)->Dump(" +- ");
  }
  if (!validation_out_edges().empty()) {
    printf(" validation out edges:\n");
    for (std::vector<Edge*>::const_iterator e = validation_out_edges().begin();
         e != validation_out_edges().end() && *e != NULL; ++e) {
      (*e)->Dump(" +- ");
    }
  }
}

bool ImplicitDepLoader::LoadDeps(Edge* edge, string* err) {
  string deps_type = edge->GetBinding("deps");
  if (!deps_type.empty())
    return LoadDepsFromLog(edge, err);

  string depfile = edge->GetUnescapedDepfile();
  if (!depfile.empty())
    return LoadDepFile(edge, depfile, err);

  // No deps to load.
  return true;
}

struct matches {
  explicit matches(std::vector<StringPiece>::iterator i) : i_(i) {}

  bool operator()(const Node* node) const {
    StringPiece opath = StringPiece(node->path());
    return *i_ == opath;
  }

  std::vector<StringPiece>::iterator i_;
};

bool ImplicitDepLoader::LoadDepFile(Edge* edge, const string& path,
                                    string* err) {
  METRIC_RECORD("depfile load");
  // Read depfile content.  Treat a missing depfile as empty.
  string content;
  switch (disk_interface_->ReadFile(path, &content, err)) {
  case DiskInterface::Okay:
    break;
  case DiskInterface::NotFound:
    err->clear();
    break;
  case DiskInterface::OtherError:
    *err = "loading '" + path + "': " + *err;
    return false;
  }
  // On a missing depfile: return false and empty *err.
  Node* first_output = edge->outputs_[0];
  if (content.empty()) {
    explanations_.Record(first_output, "depfile '%s' is missing", path.c_str());
    return false;
  }

  DepfileParser depfile(depfile_parser_options_
                        ? *depfile_parser_options_
                        : DepfileParserOptions());
  string depfile_err;
  if (!depfile.Parse(&content, &depfile_err)) {
    *err = path + ": " + depfile_err;
    return false;
  }

  if (depfile.outs_.empty()) {
    *err = path + ": no outputs declared";
    return false;
  }

  uint64_t unused;
  std::vector<StringPiece>::iterator primary_out = depfile.outs_.begin();
  CanonicalizePath(const_cast<char*>(primary_out->str_), &primary_out->len_,
                   &unused);

  // Check that this depfile matches the edge's output, if not return false to
  // mark the edge as dirty.
  StringPiece opath = StringPiece(first_output->path());
  if (opath != *primary_out) {
    explanations_.Record(first_output,
                         "expected depfile '%s' to mention '%s', got '%s'",
                         path.c_str(), first_output->path().c_str(),
                         primary_out->AsString().c_str());
    return false;
  }

  // Ensure that all mentioned outputs are outputs of the edge.
  for (std::vector<StringPiece>::iterator o = depfile.outs_.begin();
       o != depfile.outs_.end(); ++o) {
    matches m(o);
    if (std::find_if(edge->outputs_.begin(), edge->outputs_.end(), m) == edge->outputs_.end()) {
      *err = path + ": depfile mentions '" + o->AsString() + "' as an output, but no such output was declared";
      return false;
    }
  }

  return ProcessDepfileDeps(edge, &depfile.ins_, err);
}

bool ImplicitDepLoader::ProcessDepfileDeps(
    Edge* edge, std::vector<StringPiece>* depfile_ins, std::string* err) {
  // Preallocate space in edge->inputs_ to be filled in below.
  vector<Node*>::iterator implicit_dep =
      PreallocateSpace(edge, static_cast<int>(depfile_ins->size()));

  // Add all its in-edges.
  for (std::vector<StringPiece>::iterator i = depfile_ins->begin();
       i != depfile_ins->end(); ++i, ++implicit_dep) {
    uint64_t slash_bits;
    CanonicalizePath(const_cast<char*>(i->str_), &i->len_, &slash_bits);
    Node* node = state_->GetNode(*i, slash_bits);
    *implicit_dep = node;
    node->AddOutEdge(edge);
  }

  return true;
}

bool ImplicitDepLoader::LoadDepsFromLog(Edge* edge, string* err) {
  // NOTE: deps are only supported for single-target edges.
  Node* output = edge->outputs_[0];
  DepsLog::Deps* deps = deps_log_ ? deps_log_->GetDeps(output) : NULL;
  if (!deps) {
    explanations_.Record(output, "deps for '%s' are missing",
                         output->path().c_str());
    return false;
  }

  // Deps are invalid if the output is newer than the deps.
  if (output->mtime() > deps->mtime) {
    explanations_.Record(output,
                         "stored deps info out of date for '%s' (%" PRId64
                         " vs %" PRId64 ")",
                         output->path().c_str(), deps->mtime, output->mtime());
    return false;
  }

  Node** nodes = deps->nodes;
  size_t node_count = deps->node_count;
  edge->inputs_.insert(edge->inputs_.end() - edge->order_only_deps_,
                       nodes, nodes + node_count);
  edge->implicit_deps_ += node_count;
  for (size_t i = 0; i < node_count; ++i) {
    nodes[i]->AddOutEdge(edge);
  }
  return true;
}

vector<Node*>::iterator ImplicitDepLoader::PreallocateSpace(Edge* edge,
                                                            int count) {
  edge->inputs_.insert(edge->inputs_.end() - edge->order_only_deps_,
                       (size_t)count, 0);
  edge->implicit_deps_ += count;
  return edge->inputs_.end() - edge->order_only_deps_ - count;
}

void InputsCollector::VisitNode(const Node* node) {
  const Edge* edge = node->in_edge();

  if (!edge)  // A source file.
    return;

  // Add inputs of the producing edge to the result,
  // except if they are themselves produced by a phony
  // edge.
  for (const Node* input : edge->inputs_) {
    if (!visited_nodes_.insert(input).second)
      continue;

    VisitNode(input);

    const Edge* input_edge = input->in_edge();
    if (!(input_edge && input_edge->is_phony())) {
      inputs_.push_back(input);
    }
  }
}

std::vector<std::string> InputsCollector::GetInputsAsStrings(
    bool shell_escape) const {
  std::vector<std::string> result;
  result.reserve(inputs_.size());

  for (const Node* input : inputs_) {
    std::string unescaped = input->PathDecanonicalized();
    if (shell_escape) {
      std::string path;
#ifdef _WIN32
      GetWin32EscapedString(unescaped, &path);
#else
      GetShellEscapedString(unescaped, &path);
#endif
      result.push_back(std::move(path));
    } else {
      result.push_back(std::move(unescaped));
    }
  }
  return result;
}
