/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_MAIN_CPP
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_MAIN_CPP
#include <string>
#include <string.h>
#include <vector>
extern "C++" int AKA_mark(char* str);
extern "C++" void AKA_assert(char* actualName, int actualVal, char* expectedName, int expectedVal);
extern "C++" int AKA_assert_double(char* actualName, double actualVal, char* expectedName, double expectedVal);
extern "C++" int AKA_assert_ptr(char* actualName, void* actualVal, char* expectedName, void* expectedVal);
extern "C++" int AKA_fCall;
extern "C++" char* AKA_test_case_name;



/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__MAIN_H_
#define AKA_INCLUDE__MAIN_H_
#include <main.akaignore.h>
#endif


/** Instrumented function setup() */
void setup() /* << Aka begin of function void setup() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\setup()");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.setup.26.stub"


}

/** Instrumented function loop() */
void loop() /* << Aka begin of function void loop() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.loop.49.stub"

  AKA_mark("lis===8###sois===61###eois===82###lif===1###soif===17###eoif===38###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()");gearSensor.process();
  AKA_mark("lis===9###sois===86###eois===119###lif===2###soif===42###eoif===75###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()");Gear gear = gearSensor.getGear();

  // if we have any new CAN bus data
  if (AKA_mark("lis===12###sois===167###eois===207###lif===5###soif===123###eoif===163###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()") && ((AKA_mark("lis===12###sois===167###eois===187###lif===5###soif===123###eoif===143###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()") && (can.newVehicleData())) || (AKA_mark("lis===12###sois===191###eois===207###lif===5###soif===147###eoif===163###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()") && (gear != lastGear)))) {
    AKA_mark("lis===13###sois===216###eois===237###lif===6###soif===172###eoif===193###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()");Pose pose = can.pose;
    AKA_mark("lis===14###sois===243###eois===276###lif===7###soif===199###eoif===232###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()");pose.gear = gearSensor.getGear();

    AKA_mark("lis===16###sois===284###eois===301###lif===9###soif===240###eoif===257###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()");updatePose(pose);
    AKA_mark("lis===17###sois===307###eois===323###lif===10###soif===263###eoif===279###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()");lastPose = pose;
  }
else {
AKA_mark("lis===-12-###sois===-167-###eois===-16740-###lif===-5-###soif===-###eoif===-163-###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\loop()");
}

  // if we have any telemetry updates to make
  // if (SerialUSB.available())
    // processTelemetry(SerialUSB.readStringUntil('\n').c_str());

  // can.updateDashboard();
}

/** Instrumented function setupLightsAndButtons() */
void setupLightsAndButtons() /* << Aka begin of function void setupLightsAndButtons() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\setupLightsAndButtons()");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.setupLightsAndButtons.520.stub"


}

/** Instrumented function setupJoystick() */
void setupJoystick() /* << Aka begin of function void setupJoystick() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\setupJoystick()");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.setupJoystick.559.stub"


}

/** Instrumented function setupPotentiometers() */
void setupPotentiometers() /* << Aka begin of function void setupPotentiometers() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\setupPotentiometers()");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.setupPotentiometers.590.stub"

  AKA_mark("lis===36###sois===617###eois===629###lif===1###soif===32###eoif===44###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\setupPotentiometers()");SPI.begin();
}

/** Instrumented function setupCAN() */
void setupCAN() /* << Aka begin of function void setupCAN() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\setupCAN()");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.setupCAN.641.stub"

}

/** Instrumented function updatePose(Pose) */
void updatePose(Pose pose) /* << Aka begin of function void updatePose(Pose pose) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.updatePose.665.stub"

  AKA_mark("lis===43###sois===692###eois===724###lif===1###soif===32###eoif===64###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");float scaledAccel, scaledBrakes;

  AKA_mark("lis===45###sois===738###eois===742###lif===3###soif===78###eoif===82###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");switch (mode) {
    case EmulationMode::Xbox: if (mode == EmulationMode::Xbox)
AKA_mark("lis===46###sois===751###eois===776###lif===4###soif===91###eoif===116###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");

      AKA_mark("lis===47###sois===784###eois===790###lif===5###soif===124###eoif===130###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");break;
    case EmulationMode::PC: if (mode == EmulationMode::PC)
AKA_mark("lis===48###sois===796###eois===819###lif===6###soif===136###eoif===159###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");

      // steering, accelerator, and brakes
      AKA_mark("lis===50###sois===871###eois===905###lif===8###soif===211###eoif===245###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");joystick->setXAxis(pose.steering);
      AKA_mark("lis===51###sois===913###eois===962###lif===9###soif===253###eoif===302###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");joystick->setYAxis(ACCEL_MAX - pose.accelerator);
      AKA_mark("lis===52###sois===970###eois===1002###lif===10###soif===310###eoif===342###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");joystick->setZAxis(pose.brakes);

      // gear
      AKA_mark("lis===55###sois===1027###eois===1069###lif===13###soif===367###eoif===409###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");uint8_t button = buttonForGear(pose.gear);
      if (AKA_mark("lis===56###sois===1081###eois===1102###lif===14###soif===421###eoif===442###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)") && (AKA_mark("lis===56###sois===1081###eois===1102###lif===14###soif===421###eoif===442###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)") && (pose.gear != lastGear))) {
        AKA_mark("lis===57###sois===1115###eois===1164###lif===15###soif===455###eoif===504###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");joystick->releaseButton(buttonForGear(lastGear));
        // press and store new gear
        AKA_mark("lis===59###sois===1211###eois===1241###lif===17###soif===551###eoif===581###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");joystick->pressButton(button);
        AKA_mark("lis===60###sois===1251###eois===1272###lif===18###soif===591###eoif===612###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");lastGear = pose.gear;
      }
else {
AKA_mark("lis===-56-###sois===-1081-###eois===-108121-###lif===-14-###soif===-###eoif===-442-###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");
}

      // upshift pressed
      // pose.upshift ? joystick->pressButton(0) : joystick->releaseButton(0);

      // downshift pressed
      // pose.downshift ? joystick->pressButton(1) : joystick->releaseButton(1);

      // clutch
      AKA_mark("lis===70###sois===1528###eois===1596###lif===28###soif===868###eoif===936###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");pose.clutch ? joystick->pressButton(8) : joystick->releaseButton(8);

      // e-brake
      AKA_mark("lis===73###sois===1624###eois===1692###lif===31###soif===964###eoif===1032###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");pose.ebrake ? joystick->pressButton(9) : joystick->releaseButton(9);
      
      AKA_mark("lis===75###sois===1708###eois===1714###lif===33###soif===1048###eoif===1054###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");break;
  }

  // update joystick state
  AKA_mark("lis===79###sois===1753###eois===1775###lif===37###soif===1093###eoif===1115###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\updatePose(Pose)");joystick->sendState();
}

/** Instrumented function toggleEmulationMode() */
void toggleEmulationMode() /* << Aka begin of function void toggleEmulationMode() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\toggleEmulationMode()");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.toggleEmulationMode.1787.stub"

  AKA_mark("lis===83###sois===1822###eois===1826###lif===1###soif===40###eoif===44###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\toggleEmulationMode()");switch (mode) {
    case EmulationMode::Xbox: if (mode == EmulationMode::Xbox)
AKA_mark("lis===84###sois===1835###eois===1860###lif===2###soif===53###eoif===78###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\toggleEmulationMode()");

      AKA_mark("lis===85###sois===1868###eois===1893###lif===3###soif===86###eoif===111###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\toggleEmulationMode()");mode = EmulationMode::PC;
      AKA_mark("lis===86###sois===1901###eois===1907###lif===4###soif===119###eoif===125###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\toggleEmulationMode()");break;
    case EmulationMode::PC: if (mode == EmulationMode::PC)
AKA_mark("lis===87###sois===1913###eois===1936###lif===5###soif===131###eoif===154###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\toggleEmulationMode()");

      AKA_mark("lis===88###sois===1944###eois===1971###lif===6###soif===162###eoif===189###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\toggleEmulationMode()");mode = EmulationMode::Xbox;
      AKA_mark("lis===89###sois===1979###eois===1985###lif===7###soif===197###eoif===203###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\toggleEmulationMode()");break;
  }
}

/** Instrumented function processTelemetry(std::string) */
void processTelemetry(std::string data) /* << Aka begin of function void processTelemetry(std::string data) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\processTelemetry(std::string)");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.processTelemetry.2002.stub"

}

/** Instrumented function buttonForGear(Gear) */
uint8_t buttonForGear(Gear gear) /* << Aka begin of function uint8_t buttonForGear(Gear gear) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\main.cpp\\buttonForGear(Gear)");AKA_fCall++;
	/** Include stub source code */
	#include "main.cpp.buttonForGear.2053.stub"

  AKA_mark("lis===97###sois===2083###eois===2131###lif===1###soif===38###eoif===86###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\main.cpp\\buttonForGear(Gear)");return gear == gear == Gear::Reverse ? 8 : gear;
}
#endif
