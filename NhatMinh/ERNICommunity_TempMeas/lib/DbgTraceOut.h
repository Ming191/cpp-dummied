#ifndef SRC_DBGTRACEOUT_H_
#define SRC_DBGTRACEOUT_H_

class DbgTrace_Context;
class DbgPrint_Console;
class DbgTrace_Out {
public:
  DbgTrace_Out(DbgTrace_Context*, const char*, DbgPrint_Console*);
};

#endif // SRC_DBGTRACEOUT_H_ 