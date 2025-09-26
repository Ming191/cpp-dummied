#ifndef SRC_DBGTRACECONTEXT_H_
#define SRC_DBGTRACECONTEXT_H_

class DbgCli_Topic;
class DbgTrace_Context {
public:
  DbgTrace_Context(DbgCli_Topic*);
  static DbgTrace_Context* getContext();
};

#endif // SRC_DBGTRACECONTEXT_H_ 