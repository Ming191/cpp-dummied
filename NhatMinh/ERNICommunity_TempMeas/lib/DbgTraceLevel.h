#ifndef SRC_DBGTRACELEVEL_H_
#define SRC_DBGTRACELEVEL_H_

struct DbgTrace_Level {
  enum Level {
    error,
    debug
  };
  static const int info = 1;
};

#endif // SRC_DBGTRACELEVEL_H_ 