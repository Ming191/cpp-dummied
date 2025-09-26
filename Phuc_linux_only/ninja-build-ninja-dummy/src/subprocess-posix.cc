// Copyright 2012 Google Inc. All Rights Reserved.
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

#include "exit_status.h"
#include "subprocess.h"

#include <sys/select.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include "unistd.h"
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <spawn.h>

#if defined(USE_PPOLL)
#include <poll.h>
#else
#include <sys/select.h>
#endif

extern char** environ;

#include "util.h"

using namespace std;

namespace {
  ExitStatus ParseExitStatus(int status);
}

bool Subprocess::TryFinish(int waitpid_options) {
  //assert(pid_ != -1);
  int status, ret;
  while ((ret = waitpid(pid_, &status, waitpid_options)) < 0) {
    if (errno != EINTR)
      Fatal("waitpid(%d): %s", pid_, strerror(errno));
  }
  if (ret == 0)
    return false; // Subprocess is alive (WNOHANG-only).
  pid_ = -1;
  exit_status_ = ParseExitStatus(status);
  return true; // Subprocess has terminated.
}

ExitStatus Subprocess::Finish() {
  if (pid_ != -1) {
    TryFinish(0);
    //assert(pid_ == -1);
  }
  return exit_status_;
}

namespace {

ExitStatus ParseExitStatus(int status) {
#ifdef _AIX
  if (WIFEXITED(status) && WEXITSTATUS(status) & 0x80) {
    // Map the shell's exit code used for signal failure (128 + signal) to the
    // status code expected by AIX WIFSIGNALED and WTERMSIG macros which, unlike
    // other systems, uses a different bit layout.
    int signal = WEXITSTATUS(status) & 0x7f;
    status = (signal << 16) | signal;
  }
#endif

  if (WIFEXITED(status)) {
    // propagate the status transparently
    return static_cast<ExitStatus>(WEXITSTATUS(status));
  }
  if (WIFSIGNALED(status)) {
    if (WTERMSIG(status) == SIGINT || WTERMSIG(status) == SIGTERM
        || WTERMSIG(status) == SIGHUP)
      return ExitInterrupted;
  }
  // At this point, we exit with any other signal+128
  return static_cast<ExitStatus>(status + 128);
}

} // anonymous namespace

volatile sig_atomic_t SubprocessSet::interrupted_;
volatile sig_atomic_t SubprocessSet::s_sigchld_received;

void SubprocessSet::SetInterruptedFlag(int signum) {
  interrupted_ = signum;
}

void SubprocessSet::SigChldHandler(int signo, siginfo_t* info, void* context) {
  s_sigchld_received = 1;
}

void SubprocessSet::HandlePendingInterruption() {
  sigset_t pending;
  sigemptyset(&pending);
  if (sigpending(&pending) == -1) {
    //perror("ninja: sigpending");
    return;
  }
  if (sigismember(&pending, SIGINT))
    interrupted_ = SIGINT;
  else if (sigismember(&pending, SIGTERM))
    interrupted_ = SIGTERM;
  else if (sigismember(&pending, SIGHUP))
    interrupted_ = SIGHUP;
}
// Reaps console processes that have exited and moves them from the running set
// to the finished set.
void SubprocessSet::CheckConsoleProcessTerminated() {
  if (!s_sigchld_received)
    return;
  for (auto i = running_.begin(); i != running_.end(); ) {
    if ((*i)->use_console_ && (*i)->TryFinish(WNOHANG)) {
      finished_.push(*i);
      i = running_.erase(i);
    } else {
      ++i;
    }
  }
}

#ifdef USE_PPOLL
bool SubprocessSet::DoWork() {
  vector<pollfd> fds;
  nfds_t nfds = 0;

  for (vector<Subprocess*>::iterator i = running_.begin();
       i != running_.end(); ++i) {
    int fd = (*i)->fd_;
    if (fd < 0)
      continue;
    pollfd pfd = { fd, POLLIN | POLLPRI, 0 };
    fds.push_back(pfd);
    ++nfds;
  }
  if (nfds == 0) {
    // Add a dummy entry to prevent using an empty pollfd vector.
    // ppoll() allows to do this by setting fd < 0.
    pollfd pfd = { -1, 0, 0 };
    fds.push_back(pfd);
    ++nfds;
  }

  interrupted_ = 0;
  s_sigchld_received = 0;
  int ret = ppoll(&fds.front(), nfds, NULL, &old_mask_);
  // Note: This can remove console processes from the running set, but that is
  // not a problem for the pollfd set, as console processes are not part of the
  // pollfd set (they don't have a fd).
  CheckConsoleProcessTerminated();
  if (ret == -1) {
    if (errno != EINTR) {
      //perror("ninja: ppoll");
      return false;
    }
    return IsInterrupted();
  }

  // ppoll/pselect prioritizes file descriptor events over a signal delivery.
  // However, if the user is trying to quit ninja, we should react as fast as
  // possible.
  HandlePendingInterruption();
  if (IsInterrupted())
    return true;

  // Iterate through both the pollfd set and the running set.
  // All valid fds in the running set are in the pollfd, in the same order.
  nfds_t cur_nfd = 0;
  for (vector<Subprocess*>::iterator i = running_.begin();
       i != running_.end(); ) {
    int fd = (*i)->fd_;
    if (fd < 0) {
      ++i;
      continue;
    }
    //assert(fd == fds[cur_nfd].fd);
    if (fds[cur_nfd++].revents) {
      (*i)->OnPipeReady();
      if ((*i)->Done()) {
        finished_.push(*i);
        i = running_.erase(i);
        continue;
      }
    }
    ++i;
  }

  return IsInterrupted();
}

#else  // !defined(USE_PPOLL)
bool SubprocessSet::DoWork() {
  fd_set set;
  int nfds = 0;
  FD_ZERO(&set);

  for (vector<Subprocess*>::iterator i = running_.begin();
       i != running_.end(); ++i) {
    int fd = (*i)->fd_;
    if (fd >= 0) {
      FD_SET(fd, &set);
      if (nfds < fd+1)
        nfds = fd+1;
    }
  }

  interrupted_ = 0;
  s_sigchld_received = 0;
  int ret = pselect(nfds, (nfds > 0 ? &set : nullptr), 0, 0, 0, &old_mask_);
  CheckConsoleProcessTerminated();
  if (ret == -1) {
    if (errno != EINTR) {
      //perror("ninja: pselect");
      return false;
    }
    return IsInterrupted();
  }

  // ppoll/pselect prioritizes file descriptor events over a signal delivery.
  // However, if the user is trying to quit ninja, we should react as fast as
  // possible.
  HandlePendingInterruption();
  if (IsInterrupted())
    return true;

  for (vector<Subprocess*>::iterator i = running_.begin();
       i != running_.end(); ) {
    int fd = (*i)->fd_;
    if (fd >= 0 && FD_ISSET(fd, &set)) {
      (*i)->OnPipeReady();
      if ((*i)->Done()) {
        finished_.push(*i);
        i = running_.erase(i);
        continue;
      }
    }
    ++i;
  }

  return IsInterrupted();
}
#endif  // !defined(USE_PPOLL)

Subprocess* SubprocessSet::NextFinished() {
  if (finished_.empty())
    return NULL;
  Subprocess* subproc = finished_.front();
  finished_.pop();
  return subproc;
}
