#ifndef SRC_ADAFRUIT_MCP9808_H_
#define SRC_ADAFRUIT_MCP9808_H_

class Adafruit_MCP9808 {
public:
  Adafruit_MCP9808();
  bool begin(int);
  float readTempC();
};

#endif // SRC_ADAFRUIT_MCP9808_H_ 