#ifndef SRC_TM1638_H_
#define SRC_TM1638_H_

typedef unsigned short word;

class TM1638 {
public:
  void setDisplayToString(const char*, word);
};

#endif // SRC_TM1638_H_ 