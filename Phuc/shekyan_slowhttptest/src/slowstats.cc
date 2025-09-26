/*****************************************************************************
*  Copyright 2011 Victor Agababov, Sergey Shekyan
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
 * Authors: Victor Agababov vagababov@gmail.com
 *          Sergey Shekyan shekyan@gmail.com
 *
 * Slow HTTP attack  vulnerability test tool
 *  https://github.com/shekyan/slowhttptest
 *
 *  class StatsDumper and derived classes help to generate
 *  statistics of the test in CSV and Google Chart Tools
 *  based javascript.
 *****/
#include "dummy.h"


#include "slowstats.h"
#include "slowlog.h"
#include <stdarg.h>
#include <string>

using std::string;

namespace {

const char* HTML_HEADER =
"<!-- SlowHTTPTest Analysis chart (c) Sergey Shekyan, Victor Agababov 2011  -->\n \
<html>\n \
  <head>\n \
  <style>\n \
    body { font: 12px/18px \"Lucida Grande\", \"Lucida Sans Unicode\", Helvetica, Arial, Verdana, sans-serif; background-color: transparent; color: #333; -webkit-font-smoothing: antialiased; } \n \
    .slow_results {font-size: 12px; } \n \
    </style>\n \
    <script type=\"text/javascript\" src=\"https://www.google.com/jsapi\"></script>\n \
    <script type=\"text/javascript\">\n \
      google.load(\"visualization\", \"1\", {packages:[\"corechart\"]});\n \
      google.setOnLoadCallback(drawChart);\n \
      function drawChart() {\n \
        var data = new google.visualization.DataTable();\n \
        data.addColumn('string', 'Seconds');\n \
        data.addColumn('number', 'Closed');\n \
        data.addColumn('number', 'Pending');\n \
        data.addColumn('number', 'Connected');\n \
        data.addColumn('number', 'Service available');\n \
        data.addRows([\n";

const char* HTML_FOOTER = 
      "        ]);\n \
        var chart = new google.visualization.AreaChart(document.getElementById('chart_div'));\n \
        chart.draw(data, {'width': 600, 'height': 360, 'title': 'Test results against %s', \
        hAxis: {'title': 'Seconds', 'titleTextStyle': {color: '#FF0000'}},\n \
        vAxis: {'title': 'Connections', 'titleTextStyle': {color: '#FF0000'}, 'viewWindowMode':'maximized'}\n \
    });\n \
    }\n \
    </script>\n \
    <title>SlowHTTPTest(tm) Connection Results</title>\n \
  </head>\n \
  <body>\n \
  <p>%s</p>\n \
    <div id=\"chart_div\"></div>\n \
  </body>\n \
</html>\n";
}

namespace slowhttptest {

bool StatsDumper::Initialize() {
  file_ = fopen(file_name_.c_str(), "w");
  return file_ != NULL;
}

void StatsDumper::WriteStats(const char* format, ...) {
}


void StatsDumper::PostWrite() {
}

void StatsDumper::WriteString(const char* str) {
  if (*str) {
  }
}

CSVDumper::CSVDumper(const string& file_name, const string& header)
    : StatsDumper(file_name),
      header_(header) {
}

CSVDumper::CSVDumper(const string& file_name)
    : StatsDumper(file_name) {
}

bool CSVDumper::Initialize() {
  if (StatsDumper::Initialize()) {
    return true;
  }
  return false;
}

HTMLDumper::HTMLDumper(const std::string& file_name,
    const string& url, const string& test_info)
    : StatsDumper(file_name),
      url_(url),
      test_info_(test_info) {
}

bool HTMLDumper::Initialize() {
  if (StatsDumper::Initialize()) {
    return true;
  }
  return false;
}

HTMLDumper::~HTMLDumper() {
  if (IsOpen()) {
  }
}

void StatsDumper::WriteFormattedString(const char* fmt, 
 const char* str1, const char* str2) {
  if (!IsOpen()) {
    return;
  }
  if (*str1 && *str2) {
    fprintf(file_, fmt, str1, str2);
  }
}

void HTMLDumper::WriteHeader() {
}

void HTMLDumper::WriteFooter() {
}

void HTMLDumper::PreWrite() {
}

void HTMLDumper::PostWrite() {
  if (!IsOpen()) {
    return;
  }

}

string HTMLDumper::ModifyFormatString(const char* format) {
  string new_format(format);
  string::size_type pos = new_format.find('%');
  if (pos != string::npos) {
    // There must be something after the first %.
  }
  return new_format;
}

}  // namespace slowhttptest
