#ifndef SRC_DBGCLITOPIC_H_
#define SRC_DBGCLITOPIC_H_

class DbgCli_Node;
class DbgCli_Topic : public DbgCli_Node {
public:
  DbgCli_Topic(DbgCli_Node*, const char*, const char*);
};

#endif // SRC_DBGCLITOPIC_H_ 