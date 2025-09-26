#include "due_can.h"
#include "SPI.h"
#include "GearSensor.h"
bool CANRaw::sendFrame(CAN_FRAME &frame) {}
bool CANRaw::available() {}
bool CANRaw::read(CAN_FRAME &frame) {}

CANRaw Can0(0);
CANRaw Can1(1);
CANRaw::CANRaw(int bus) {}

SPIClass SPI;

void GearSensor::process() {}