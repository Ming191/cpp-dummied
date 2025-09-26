#include <main.h>

void setup() {

}

void loop() {
  gearSensor.process();
  Gear gear = gearSensor.getGear();

  // if we have any new CAN bus data
  if (can.newVehicleData() || gear != lastGear) {
    Pose pose = can.pose;
    pose.gear = gearSensor.getGear();

    updatePose(pose);
    lastPose = pose;
  }

  // if we have any telemetry updates to make
  // if (SerialUSB.available())
    // processTelemetry(SerialUSB.readStringUntil('\n').c_str());

  // can.updateDashboard();
}

void setupLightsAndButtons() {

}

void setupJoystick() {

}

void setupPotentiometers() {
  SPI.begin();
}

void setupCAN() {
}

void updatePose(Pose pose) {
  float scaledAccel, scaledBrakes;

  switch (mode) {
    case EmulationMode::Xbox:
      break;
    case EmulationMode::PC:
      // steering, accelerator, and brakes
      joystick->setXAxis(pose.steering);
      joystick->setYAxis(ACCEL_MAX - pose.accelerator);
      joystick->setZAxis(pose.brakes);

      // gear
      uint8_t button = buttonForGear(pose.gear);
      if (pose.gear != lastGear) {
        joystick->releaseButton(buttonForGear(lastGear));
        // press and store new gear
        joystick->pressButton(button);
        lastGear = pose.gear;
      }

      // upshift pressed
      // pose.upshift ? joystick->pressButton(0) : joystick->releaseButton(0);

      // downshift pressed
      // pose.downshift ? joystick->pressButton(1) : joystick->releaseButton(1);

      // clutch
      pose.clutch ? joystick->pressButton(8) : joystick->releaseButton(8);

      // e-brake
      pose.ebrake ? joystick->pressButton(9) : joystick->releaseButton(9);
      
      break;
  }

  // update joystick state
  joystick->sendState();
}

void toggleEmulationMode() {
  switch (mode) {
    case EmulationMode::Xbox:
      mode = EmulationMode::PC;
      break;
    case EmulationMode::PC:
      mode = EmulationMode::Xbox;
      break;
  }
}

void processTelemetry(std::string data) {
}

uint8_t buttonForGear(Gear gear) {
  return gear == gear == Gear::Reverse ? 8 : gear;
}