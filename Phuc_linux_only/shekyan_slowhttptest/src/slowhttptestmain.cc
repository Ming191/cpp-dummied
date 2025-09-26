/*****************************************************************************
*  Copyright 2011 Sergey Shekyan, Victor Agababov
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
 *         Victor Agababov vagababov@gmail.com
 *
 * Slow HTTP attack vulnerability test tool
 * https://github.com/shekyan/slowhttptest
 *****/
#include "dummy.h"

#include <getopt.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <memory>
#include <cctype>

#include "slowlog.h"
#include "slowhttptest.h"

#define DEFAULT_URL "http://localhost/"

#ifdef HAVE_CXX11
#  define UNIQUE_PTR std::unique_ptr
#else
#  define UNIQUE_PTR std::auto_ptr
#endif

static void info() {
}
static void usage() {
}

int getopt(int argc, char * const argv[], const char *optstring) {
    // Always return -1 to indicate no more options
    return -1;
}

static bool check_window_range(int a,int b) {
  if(a > b) {
    printf("Error: start value of the advertised window range "
       "is higher (%d) than the end value (%d)\r\n", a, b);
    info();
    return  false;
  }
  return true;
}

static bool parse_int(int &val, long max = INT_MAX) {
  long tmp = strtol(optarg, 0, 10);
  if(tmp == 0) { //not last empty argument
    printf("Option -%c requires an argument.\n", optopt);
    info();
    return false;
  } else if(tmp < 0 || tmp > max) {
    printf("Error: invalid -%c value %ld, max: %ld\r\n",optopt, tmp, max);
    info();
    return false;
  } else {
    val = static_cast<int>(tmp);
    return true;
  }
}

// global flag to indicite if we need to run
int g_running = true;

void int_handler(int param) {
  g_running = false;  
}

using slowhttptest::slowlog_init;
using slowhttptest::slowlog;
using slowhttptest::SlowHTTPTest;
using slowhttptest::SlowTestType;
using slowhttptest::ProxyType;

int main2(int argc, char **argv) {

  if (argc < 1) {
    info();
    return -1;
  }
  char url[1024] = { 0 };
  char path[1024] = { 0 };
  char proxy[1024] = { 0 };
  char verb[16] = { 0 };
  char content_type[1024] = { 0 };
  char accept[1024] = { 0 };
  char cookie[1024] = { 0 };
  char header[1024] = { 0 };
  // default values
  int conn_cnt            = 50;
  int content_length      = 4096;
  int duration            = 240;
  int interval            = 10;
  int max_random_data_len = 32;
  int probe_interval      = 5;
  int range_start         = 5;
  int range_limit         = 2000;
  int rate                = 50;
  int read_interval       = 1;
  int read_len            = 5;
  int pipeline_factor     = 1;
  int debug_level         = LOG_INFO;
  bool  need_stats        = false;
  int window_upper_limit  = 512;
  int window_lower_limit  = 1;
  SlowTestType type = slowhttptest::eHeader;
  ProxyType proxy_type = slowhttptest::eNoProxy;
  long tmp;
  int o;
  while((o = getopt(argc, argv, ":HBRXgha:b:c:d:e:f:i:j:k:l:m:n:o:p:r:s:t:u:v:w:x:y:z:1:")) != -1) {
    switch (o) {
      case 'a':
        if(!parse_int(range_start, 65539))
          return -1;
        break;
      case 'b':
        if(!parse_int(range_limit, 524288))
          return -1;
        break;
      case 'c':
#ifdef HAVE_POLL
        if(!parse_int(conn_cnt, 65539))
#else
        if(!parse_int(conn_cnt, 1024))
#endif
          return -1;
        break;
      case 'd':
        strncpy(proxy, optarg, 1023);
        proxy_type = slowhttptest::eHTTPProxy;
        break;
      case 'e':
        strncpy(proxy, optarg, 1023);
        proxy_type = slowhttptest::eProbeProxy;
        break;
      case 'f':
        strncpy(content_type, optarg, 1023);
        break;
      case 'h':
        usage();
        return 1;
        break;
      case 'H':
        type = slowhttptest::eHeader;
        break;
      case 'B':
        type = slowhttptest::ePost;
        break;
      case 'R':
        type = slowhttptest::eRange;
        break;
      case 'X':
        type = slowhttptest::eSlowRead;
        break;
      case 'g':
        need_stats = true;
        break;
      case 'i':
        if(!parse_int(interval))
          return -1;
        break;
      case 'j':
        strncpy(cookie, optarg, 1023);
        break;
      case '1':
        strncpy(header, optarg, 1023);
        break;
      case 'k':
        if(!parse_int(pipeline_factor, 10))
          return -1;
        break;
      case 'l':
        if(!parse_int(duration))
          return -1;
        break;
      case 'm':
        strncpy(accept, optarg, 1023);
        break;
      case 'n':
        if(!parse_int(read_interval))
          return -1;
        break;
      case 'o':
        strncpy(path, optarg, 1023);
        break;
      case 'p':
        if(!parse_int(probe_interval))
          return -1;
        break;
      case 'r':
        if(!parse_int(rate))
          return -1;
        break;
      case 's':
        if(!parse_int(content_length))
          return -1;
        break;
      case 't':
        strncpy(verb, optarg, 15);
        break;
      case 'u':
        strncpy(url, optarg, 1023);
        break;
      case 'v':
        tmp = strtol(optarg, 0, 10);
        if(0 <= tmp && tmp <= 4) {
          debug_level = static_cast<int>(tmp);
        } else {
          debug_level = LOG_FATAL;
        }
        break;
      case 'w':
        if(!parse_int(window_lower_limit))
          return -1;
        break;
      case 'x':
        if(!parse_int(max_random_data_len))
          return -1;
        else
          if(max_random_data_len < 2) max_random_data_len = 2;
        break;
      case 'y':
        if(!parse_int(window_upper_limit))
          return -1;
        break;
      case 'z':
        if(!parse_int(read_len))
          return -1;
        break;
      case '?':
        printf("Illegal option -%c\n", optopt);
        info();
        return -1;
        break;
      default:
        printf("Option -%c requires an argument.\n", optopt);
        info();
        return -1;
    }
  }
  int index;
  if(slowhttptest::eSlowRead == type 
      && !check_window_range(window_lower_limit, window_upper_limit))
    return -1;
  if(!strlen(url)) {
    strncpy(url, DEFAULT_URL, sizeof(url));
  }
  signal(SIGPIPE, SIG_IGN);
  signal(SIGINT, &int_handler);
  slowlog_init(debug_level, NULL);
  UNIQUE_PTR<SlowHTTPTest> slow_test(
      new SlowHTTPTest(rate, duration, interval,
      conn_cnt, max_random_data_len, content_length,
      type, need_stats, pipeline_factor, probe_interval,
      range_start, range_limit, read_interval, read_len,
      window_lower_limit, window_upper_limit, proxy_type, debug_level));
  if(!slow_test->init(url, verb, path, proxy, content_type, accept, cookie, header)) {
    slowlog(LOG_FATAL, "%s: error setting up slow HTTP test\n", __FUNCTION__);
    return -1;
  } else if(!slow_test->run_test()) {
    slowlog(LOG_FATAL, "%s: error running slow HTTP test\n", __FUNCTION__);
    return -1;
  }
  slow_test->report_final();
  return 0;
}
