#ifndef SRC_DBGCLICOMMAND_H_
#define SRC_DBGCLICOMMAND_H_

class DbgCli_Topic;
class DbgCli_Command {
public:
  DbgCli_Command(DbgCli_Topic*, const char*, const char*);
  virtual void execute(unsigned int, const char**, unsigned int);
  virtual const char* getHelpText();
};

#endif // SRC_DBGCLICOMMAND_H_ 