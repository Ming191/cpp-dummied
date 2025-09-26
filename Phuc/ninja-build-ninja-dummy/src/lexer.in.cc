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

#include "lexer.h"

#include <stdio.h>

#include "eval_env.h"
#include "util.h"

using namespace std;

Lexer::Token Lexer::ReadToken() {
  const char* p = ofs_;
  const char* q;
  const char* start;
  Lexer::Token token;
  for (;;) {
    start = p;
    /*!re2c
    re2c:define:YYCTYPE = "unsigned char";
    re2c:define:YYCURSOR = p;
    re2c:define:YYMARKER = q;
    re2c:yyfill:enable = 0;

    nul = "\000";
    simple_varname = [a-zA-Z0-9_-]+;
    varname = [a-zA-Z0-9_.-]+;

    [ ]*"#"[^\000\n]*"\n" { continue; }
    [ ]*"\r\n" { token = NEWLINE;  break; }
    [ ]*"\n"   { token = NEWLINE;  break; }
    [ ]+       { token = INDENT;   break; }
    "build"    { token = BUILD;    break; }
    "pool"     { token = POOL;     break; }
    "rule"     { token = RULE;     break; }
    "default"  { token = DEFAULT;  break; }
    "="        { token = EQUALS;   break; }
    ":"        { token = COLON;    break; }
    "|@"       { token = PIPEAT;   break; }
    "||"       { token = PIPE2;    break; }
    "|"        { token = PIPE;     break; }
    "include"  { token = INCLUDE;  break; }
    "subninja" { token = SUBNINJA; break; }
    varname    { token = IDENT;    break; }
    nul        { token = TEOF;     break; }
    [^]        { token = ERROR;    break; }
    */
  }

  last_token_ = start;
  ofs_ = p;
  if (token != NEWLINE && token != TEOF)
    EatWhitespace();
  return token;
}

bool Lexer::PeekToken(Token token) {
  Token t = ReadToken();
  if (t == token)
    return true;
  UnreadToken();
  return false;
}

void Lexer::EatWhitespace() {
  const char* p = ofs_;
  const char* q;
  for (;;) {
    ofs_ = p;
    /*!re2c
    [ ]+    { continue; }
    "$\r\n" { continue; }
    "$\n"   { continue; }
    nul     { break; }
    [^]     { break; }
    */
  }
}

bool Lexer::ReadIdent(string* out) {
  const char* p = ofs_;
  const char* start;
  for (;;) {
    start = p;
    /*!re2c
    varname {
      out->assign(start, p - start);
      break;
    }
    [^] {
      last_token_ = start;
      return false;
    }
    */
  }
  last_token_ = start;
  ofs_ = p;
  EatWhitespace();
  return true;
}

bool Lexer::ReadEvalString(EvalString* eval, bool path, string* err) {
  const char* p = ofs_;
  const char* q;
  const char* start;
  for (;;) {
    start = p;
    /*!re2c
    [^$ :\r\n|\000]+ {
      eval->AddText(StringPiece(start, p - start));
      continue;
    }
    "\r\n" {
      if (path)
        p = start;
      break;
    }
    [ :|\n] {
      if (path) {
        p = start;
        break;
      } else {
        if (*start == '\n')
          break;
        eval->AddText(StringPiece(start, 1));
        continue;
      }
    }
    "$$" {
      eval->AddText(StringPiece("$", 1));
      continue;
    }
    "$ " {
      eval->AddText(StringPiece(" ", 1));
      continue;
    }
    "$\r\n"[ ]* {
      continue;
    }
    "$\n"[ ]* {
      continue;
    }
    "${"varname"}" {
      eval->AddSpecial(StringPiece(start + 2, p - start - 3));
      continue;
    }
    "$"simple_varname {
      eval->AddSpecial(StringPiece(start + 1, p - start - 1));
      continue;
    }
    "$:" {
      eval->AddText(StringPiece(":", 1));
      continue;
    }
    "$". {
      last_token_ = start;
      return Error("bad $-escape (literal $ must be written as $$)", err);
    }
    nul {
      last_token_ = start;
      return Error("unexpected EOF", err);
    }
    [^] {
      last_token_ = start;
      return Error(DescribeLastError(), err);
    }
    */
  }
  last_token_ = start;
  ofs_ = p;
  if (path)
    EatWhitespace();
  // Non-path strings end in newlines, so there's no whitespace to eat.
  return true;
}
