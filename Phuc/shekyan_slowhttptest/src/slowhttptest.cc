/*****************************************************************************
*  Copyright 2011 Sergey Shekyan
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
* *****************************************************************************/

/*****
 * Author: Sergey Shekyan shekyan@gmail.com
 *
 * Slow HTTP attack vulnerability test tool
 *  https://github.com/shekyan/slowhttptest
 *****/
// #include "config.h"
#include "slowhttptest.h"

// #include <errno.h>
#include <math.h>
// #include <stdio.h>
// #include <unistd.h>
#include "dummy.h"

// #include <numeric>
// #include <sstream>
#include <string>
#include <cstring>
#include <vector>

// #include <netdb.h>
// #include <netinet/in.h>
#ifdef HAVE_POLL
#include <sys/poll.h>
#endif
// #include <sys/time.h>
// #include <sys/resource.h>
// #include <sys/socket.h>

#include "range-generator.h"
#include "slowlog.h"
#include "slowsocket.h"
#include "slowhttptest.h"
#include "slowstats.h"
#include "text-generator.h"

// Global flag to indicate if we need to run.
extern int g_running;

namespace {
static const int kBufSize = 65537;
// update ExitStatusType too
static const char* exit_status_msg[] = {
    "Hit test time limit",
    "No open connections left",
    "Cannot establish connection",
    "Connection refused",
    "Cancelled by user",
    "Unexpected error"
};
// update ProxyType too 
static const char* proxy_type_name[] = {
    "HTTP proxy at ",
    "HTTP tunnel at ",
    "SOCKS 4 at ",
    "SOCKS 5 at ",
    "probe proxy at ",
    "no proxy"
};
static const char* test_type_name[] = {
    "SLOW HEADERS",
    "SLOW BODY",
    "RANGE",
    "SLOW READ"
};
static const char* user_agents[] = {
    "Mozilla"
};
static const char referer[] = 
    "Referer: TESTING_PURPOSES_ONLY\r\n";
static const char content_type_default[] = "Content-Type: application/x-www-form-urlencoded\r\n";
static const char accept_default[] = "Accept: text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5\r\n"; 
static const char post_request[] = "Connection: close\r\n"
    "\r\n"
    "foo=bar";
// per RFC 2616 section 4.2, header can be any US_ASCII character (0-127),
// but we'll start with X-
static const char header_prefix[] = "X-";
static const char header_separator[] = ": ";

static const char body_prefix[] = "&";
static const char body_separator[] = "=";

static const char crlf[] = "\r\n";
static const char peer_closed[] = "Peer closed connection";

}  // namespace

namespace slowhttptest {
SlowHTTPTest::SlowHTTPTest(int delay, int duration, 
                           int interval, int con_cnt,
                           int max_random_data_len,
                           int content_length, SlowTestType type,
                           bool need_stats, int pipeline_factor, 
                           int probe_interval,
                           int range_start, int range_limit,
                           int read_interval, int read_len,
                           int window_lower_limit,
                           int window_upper_limit,
                           ProxyType proxy_type,
                           int debug_level)
    : probe_socket_(0),
      delay_(delay),
      duration_(duration),
      followup_timing_(interval),
      followup_cnt_(duration_ / followup_timing_),
      num_connections_(con_cnt),
      pipeline_factor_(pipeline_factor),
      probe_timeout_(probe_interval),
      extra_data_max_len_(max_random_data_len),
      seconds_passed_(0),
      content_length_(content_length),
      test_type_(type),
      need_stats_(need_stats),
      range_start_(range_start),
      range_limit_(range_limit),
      exit_status_(eCancelledByUser),
      extra_data_max_len_total_(0),
      read_interval_(read_interval),
      read_len_(read_len),
      window_lower_limit_(window_lower_limit),
      window_upper_limit_(window_upper_limit),
      is_dosed_(false),
      proxy_type_(proxy_type),
      debug_level_(debug_level) {
}

SlowHTTPTest::~SlowHTTPTest() {
  if (addr_) {
    freeaddrinfo(addr_);
  }
  if(probe_socket_) {
    delete probe_socket_;
  }

  dumpers_.clear();
  if(sock_.size() > 0) {
  }
  sock_.clear();
}

bool SlowHTTPTest::change_fd_limits() {
  rlimit fd_limit = {0, 0};
  if(getrlimit(RLIMIT_NOFILE, &fd_limit)) {
    // slowlog(LOG_ERROR, " error getting limits for open files: %s\n", strerror(errno));
    return false;
  }
  // +3 is stdin, stdout, stderr + 2 for stat fds + 4 spare
  if(fd_limit.rlim_cur != RLIM_INFINITY && fd_limit.rlim_cur < (unsigned)(num_connections_ + 10)) { //extend limits
    if(fd_limit.rlim_max == RLIM_INFINITY || fd_limit.rlim_max > (unsigned)(num_connections_ + 10)) {
      fd_limit.rlim_cur = num_connections_ + 10;
    } else { // max limit is lower than requested
      fd_limit.rlim_cur = fd_limit.rlim_max;
      num_connections_ = fd_limit.rlim_max - 6;
      slowlog(LOG_INFO, " hit system limit for open fds: %d. \n"
	"Decreasing target connection number to %d\n",
	fd_limit.rlim_max,
        num_connections_);
    }
    if(setrlimit(RLIMIT_NOFILE, &fd_limit)) {
      // slowlog(LOG_ERROR, " error setting limits for open files: %s\n", strerror(errno));
      // return false;
    } else {
      slowlog(LOG_INFO, " set open files limit to %d\n", fd_limit.rlim_cur);
    }
  }
  return true;
}

const char* SlowHTTPTest::get_random_extra() {
  random_extra_.append(textgen_.get_text(extra_data_max_len_));
  if(postfix_) {
    random_extra_.append(postfix_);
  }
}

bool SlowHTTPTest::init(const char* url, const char* verb,
    const char* path, const char* proxy,
    const char* content_type, const char* accept, const char* cookie, const char* header) {
  if(!change_fd_limits()) {
    slowlog(LOG_INFO, "error setting open file limits\n");
    
  }
  if(!base_uri_.prepare(url)) {
    slowlog(LOG_FATAL, "Error parsing URL\n");
    return false;
  }
  if(eNoProxy == proxy_type_) {
    if(!resolve_addr(base_uri_.getHost().c_str(), base_uri_.getPortStr(), &addr_, base_uri_.isLiteralIPv6())) {
      return false;
    } 
  } else {
    if(base_uri_.isSSL()) {
      slowlog(LOG_FATAL, "TLS/SSL connections through proxy are not supported yet.\n");
      return false;
    }
    if(proxy != 0 && strlen(proxy)) {
      if(!proxy_.prepare(proxy)) {
        slowlog(LOG_FATAL, "Error parsing proxy information\n");
        return false;
      } else {
        if(eHTTPProxy == proxy_type_) {
          if(!resolve_addr(proxy_.getHost().c_str(), proxy_.getPortStr(), &addr_)) {
            return false;
          }
        }
        if(eProbeProxy == proxy_type_) {
          if(!resolve_addr(base_uri_.getHost().c_str(), base_uri_.getPortStr(), &addr_)) {
            return false;
          }
          if(!resolve_addr(base_uri_.getHost().c_str(), proxy_.getPortStr(), &probe_proxy_addr_)) {
            return false;
          } 
        }
      }
    } else {
      slowlog(LOG_FATAL, "No proxy specified\n");
      return false;
    }
  }

  extra_data_max_len_total_ = extra_data_max_len_ * 2 + (eHeader == test_type_ ? 4 : 2);
  random_extra_.resize(extra_data_max_len_total_); // including separators
  user_agent_.append(user_agents[rand() % sizeof(user_agents)/sizeof(*user_agents)]);
  // promise to rewrite this mess in next release
  if(eHeader == test_type_) {
    // setup follow up data pattern
    separator_ = header_separator;
    prefix_ = header_prefix;
    postfix_ = crlf;
    // setup verb
    if(verb != 0 && strlen(verb)) {
      verb_.append(verb);
    } else {
      verb_.append("GET");
    }
  } else if(ePost == test_type_) {
    // setup follow up data pattern
    separator_ = body_separator;
    prefix_ = body_prefix;
    postfix_ = 0;
    if(strlen(verb)) {
      verb_.append(verb);
    } else {
      verb_.append("POST");
    }
  } else if(eRange == test_type_) {
    if(strlen(verb)) {
      verb_.append(verb);
    } else {
      verb_.append("HEAD");
    }
  } else if(eSlowRead == test_type_) {
    verb_.append("GET");
  }
  // Content-type
  if(content_type != 0 && strlen(content_type)) {
    content_type_.append("Content-Type: ");
    content_type_.append(content_type);
    content_type_.append(crlf);
  } else {
    content_type_.append(content_type_default);
  }
  // Accept
  if(accept != 0 && strlen(accept)) {
    accept_.append("Accept: ");
    accept_.append(accept);
    accept_.append(crlf);
  } else {
    accept_.append(accept_default);
  }

  // start building request
  request_.clear();
  request_.append(verb_);
  request_.append(" ");
  if(eHTTPProxy == proxy_type_)
    request_.append(base_uri_.getData());
  else
    request_.append(base_uri_.getPath());
  request_.append(" HTTP/1.1\r\n");
  request_.append("Host: ");
  request_.append(base_uri_.getHost());

  if(base_uri_.getPort() != 80 && base_uri_.getPort() != 443) {
    // request_.append(":");
    // std::stringstream ss;
    // ss << base_uri_.getPort();
    // request_.append(ss.str());
  }

  request_.append("\r\n");
  request_.append("User-Agent: ");
  request_.append(user_agent_);
  request_.append("\r\n");
  request_.append(referer);
  // Cookie
  if (cookie != 0 && strlen(cookie)) {
    cookie_.append(cookie);
    request_.append("Cookie: ");
    request_.append(cookie_);
    request_.append(crlf);
  }
  // Header
  if (header != 0 && strlen(header)) {
    header_.append(header);
    request_.append(header_);
    request_.append(crlf);
  }
  // method for probe is always GET
  probe_request_.append("GET");
  if(eProbeProxy == proxy_type_) {
    probe_request_.append(" ");
    probe_request_.append(base_uri_.getData());
    probe_request_.append(request_.begin() + verb_.size() + 1 + base_uri_.getPathLen(), request_.end());
  } else {
    probe_request_.append(request_.begin() + verb_.size(), request_.end());
  }
  probe_request_.append("\r\n");
  if(ePost == test_type_) {
    // request_.append("Content-Length: ");
    // std::stringstream ss;
    // ss << content_length_;
    // request_.append(ss.str());
    // request_.append("\r\n");
    // request_.append(content_type_);
    // request_.append(accept_);
    // request_.append(post_request);
  } else if(eRange == test_type_) {
    GenerateRangeHeader(range_start_, 1, range_limit_, &request_);
  }

  if(eSlowRead == test_type_) {
    if(pipeline_factor_ > 1) {
      request_.append("Connection: Keep-Alive\r\n");
      request_.reserve(request_.length() * pipeline_factor_);
    }
    request_.append("\r\n");
    size_t len = request_.length();
  }
  // init statistics
  if(need_stats_) {
    char csv_file_name[1024] = {0};
    char html_file_name[1024] = {0};
    if(path && strlen(path)) {
      sprintf(csv_file_name, "%s.csv", path);  
      sprintf(html_file_name, "%s.html", path);  
    } else {
      time_t rawtime;
      struct tm * timeinfo;
      time(&rawtime);
      timeinfo = localtime(&rawtime);
      strftime(csv_file_name, 29, "slow_%Y-%m-%d_%H-%M-%S.csv", timeinfo);
      strftime(html_file_name, 30, "slow_%Y-%m-%d_%H-%M-%S.html", timeinfo);
    }
    csv_report_.append(csv_file_name);
    html_report_.append(html_file_name);
    char test_info[1024];
    if(eSlowRead != test_type_) { 

    } else {

    }
  }
  //report_parameters();
  return true;
}

void SlowHTTPTest::close_sock(int id) {
  sock_[id]->close();
}

void SlowHTTPTest::report_final() {
  slowlog(LOG_INFO, cCYA"\nTest ended on %dth second\n"
      "Exit status:" cLCY" %s\n" cRST,
      seconds_passed_,
      exit_status_msg[exit_status_]
      );
  if(need_stats_) {
    printf(cCYA"CSV report saved to " cLCY "%s\n" cRST,
    csv_report_.c_str());
    printf(cCYA"HTML report saved to " cLCY "%s\n" cRST,
    html_report_.c_str());
  }
}

void SlowHTTPTest::report_parameters() {
  if(LOG_INFO == debug_level_) {
      slowlog(LOG_INFO, "\x1b[H\x1b[2J");
  }
  if(eSlowRead != test_type_) {
  } else { // slow read
  }
}

void SlowHTTPTest::report_status(bool to_stats) {
  initializing_ = 0;
  connecting_ = 0; 
  connected_ = 0; 
  errored_ = 0; 
  closed_ = 0;

  std::vector<SlowSocket*>::iterator it;
  SocketState state;

    if((*it)) {
      state = (*it)->get_state();
      switch(state) {
        case eInit:
          ++initializing_;
          break;
        case eConnecting:
          ++connecting_;
          break;
        case eConnected:
          ++connected_;
          break;
        case eError:
          ++errored_;
          break;
        case eClosed:
          ++closed_;
          break;
        default:
          slowlog(LOG_ERROR, "Unknown socket state: %d", state);
          break;
       }
    }
  

  if(to_stats) {
  } else {
  }
}

bool SlowHTTPTest::resolve_addr(const char* host, const char* port, addrinfo  **addr, bool is_ipv6) {
  int error;
  addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  if(is_ipv6) {
    hints.ai_family = PF_INET6;
    hints.ai_flags = AI_NUMERICHOST;
  } else {
    hints.ai_family = PF_UNSPEC;
  }
  hints.ai_socktype = SOCK_STREAM;
  // resolve the domain name into a list of addresses
  error = getaddrinfo(host, port, &hints, addr);
  if(error != 0) {
    slowlog(LOG_FATAL, "Error in getaddrinfo: %s\n", gai_strerror(error));
    return false;
  }
  return true;
}

bool SlowHTTPTest::run_test() {
  return true;
}
}  // namespace slowhttptest
