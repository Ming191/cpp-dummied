#ifndef SRC_DBGCLINODE_H_
#define SRC_DBGCLINODE_H_

class DbgCli_Node {
public:
  static void AssignRootNode(DbgCli_Node*);
  static DbgCli_Node* RootNode();
  virtual void execute(unsigned int, const char**, unsigned int);
};

#endif // SRC_DBGCLINODE_H_ 