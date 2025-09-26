#ifndef SRC_DBGTRACEPORT_H_
#define SRC_DBGTRACEPORT_H_

class DbgTrace_Port {
public:
  DbgTrace_Port(const char*, int);
};

#define TR_PRINT_STR(port, level, str) ((void)0)

#endif // SRC_DBGTRACEPORT_H_ 