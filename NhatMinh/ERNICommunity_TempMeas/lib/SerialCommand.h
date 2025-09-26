#ifndef SRC_SERIALCOMMAND_H_
#define SRC_SERIALCOMMAND_H_

class SerialCommand {
public:
  SerialCommand();
  void addCommand(const char*, void(*)());
  void setDefaultHandler(void(*)(const char *));
  char* next();
};

#endif // SRC_SERIALCOMMAND_H_ 