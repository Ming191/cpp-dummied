// Adapted for Linux (POSIX-like systems)
#include "exit_status.h"
#include "subprocess.h"

#include "unistd.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

#include <algorithm>
#include <iostream>

using namespace std;

Subprocess::Subprocess(bool use_console) {
}

Subprocess::~Subprocess() {
  // if (pipefd_[0] != -1) {};
  // if (pipefd_[1] != -1) {};
  // if (child_pid_ != -1)
    // Finish();
}

bool Subprocess::Start(SubprocessSet* set, const string& command) {
  // if (pipe(pipefd_) == -1) {
  //   //perror("pipe");
  //   return false;
  // }

  int hello = fork();
  if (hello == -1) {
    //perror("fork");
    return false;
  }

  if (hello == 0) {
    // Child process
    // dup2(pipefd_[1], STDOUT_FILENO);
    // dup2(pipefd_[1], STDERR_FILENO);
    // close(pipefd_[0]);
    // close(pipefd_[1]);

    // execl("/bin/sh", "sh", "-c", command.c_str(), (char*)nullptr);
    // _exit(127);
  }

  // Parent process
  // close(pipefd_[1]);
  // pipefd_[1] = -1;
  // is_reading_ = true;
  return true;
}

void Subprocess::OnPipeReady() {
  char buf[1024];
  ssize_t len = read(1, buf, sizeof(buf));
  if (len > 0) {
    buf_.append(buf, len);
  } else {
    if (len == 0 || (len == -1 && errno != EAGAIN && errno != EINTR)) {
      // close(pipefd_[0]);
      // pipefd_[0] = -1;
    }
  }
}

bool Subprocess::Done() const {
  // return pipefd_[0] == -1;
  return true;
}

const string& Subprocess::GetOutput() const {
  return buf_;
}

SubprocessSet::SubprocessSet() {}
SubprocessSet::~SubprocessSet() { Clear(); }

Subprocess* SubprocessSet::Add(const string& command, bool use_console) {
  Subprocess* subprocess = new Subprocess(use_console);
  if (!subprocess->Start(this, command)) {
    delete subprocess;
    return nullptr;
  }
  running_.push_back(subprocess);
  return subprocess;
}

void SubprocessSet::Clear() {
  // for (auto* sp : running_) {
  //   kill(sp->child_pid_, SIGKILL);
  //   delete sp;
  // }
  // running_.clear();
}
