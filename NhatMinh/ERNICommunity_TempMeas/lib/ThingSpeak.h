#ifndef SRC_THINGSPEAK_H_
#define SRC_THINGSPEAK_H_

class ThingSpeakClass {
public:
  void setField(int, float);
  int writeFields(int, const char*);
};

extern ThingSpeakClass ThingSpeak;

#endif // SRC_THINGSPEAK_H_ 