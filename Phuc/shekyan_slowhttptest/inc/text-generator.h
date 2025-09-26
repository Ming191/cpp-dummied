
#ifndef __SLOW_HTTP_TEST_TEXT_GENERATOR_H__
#define __SLOW_HTTP_TEST_TEXT_GENERATOR_H__

#include <stdlib.h>
#include <time.h>

#include <string>

namespace slowhttptest {

class TextGenerator {
 public:
  TextGenerator() {};
  virtual ~TextGenerator() {}

  virtual std::string GetText(size_t len) = 0;
  virtual void get_text(size_t len, std::string* where) = 0;
};


class RandomTextGenerator {
 public:
  RandomTextGenerator() { ::srand(time(NULL)); }
  virtual ~RandomTextGenerator() {}
  virtual void get_text(size_t len, std::string* where);
  virtual std::string get_text(size_t len);
};

}  // namespace slowhttptest
#endif  // __SLOW_HTTP_TEST_TEXT_GENERATOR_H__
