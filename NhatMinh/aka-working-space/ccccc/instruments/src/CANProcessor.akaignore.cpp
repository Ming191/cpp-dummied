/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_CANPROCESSOR_CPP
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_CANPROCESSOR_CPP
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
#ifndef AKA_INCLUDE__CANPROCESSOR_H_
#define AKA_INCLUDE__CANPROCESSOR_H_
#include <CANProcessor.akaignore.h>
#endif


/** Instrumented function CANProcessor::updateTelemetry(float,int) */
void CANProcessor::updateTelemetry(float speed, int rpm) /* << Aka begin of function void CANProcessor::updateTelemetry(float speed, int rpm) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::updateTelemetry(float,int)");AKA_fCall++;
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.updateTelemetry.34.stub"

  AKA_mark("lis===4###sois===91###eois===106###lif===1###soif===62###eoif===77###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::updateTelemetry(float,int)");_speed = speed;
  AKA_mark("lis===5###sois===110###eois===121###lif===2###soif===81###eoif===92###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::updateTelemetry(float,int)");_rpm = rpm;
}

/** Instrumented function CANProcessor::updateDashboard() */
void CANProcessor::updateDashboard() /* << Aka begin of function void CANProcessor::updateDashboard() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::updateDashboard()");AKA_fCall++;
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.updateDashboard.133.stub"

  // lastTransmissionFrame.data.byte[4] = _rpm % 256;
  // lastTransmissionFrame.data.byte[5] = _rpm / 256 + 0x80;
  AKA_mark("lis===11###sois===287###eois===325###lif===3###soif===159###eoif===197###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::updateDashboard()");Can0.sendFrame(lastTransmissionFrame);

  AKA_mark("lis===13###sois===331###eois===407###lif===5###soif===203###eoif===279###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::updateDashboard()");union {
    uint16_t convertedSpeed;
    uint8_t bytes[2];
  } speedData;

  // speedData.convertedSpeed = round(_speed / 0.05747);
  // lastBrakeSpeedFrame.data.byte[0] = speedData.bytes[0];
  // lastBrakeSpeedFrame.data.byte[1] = speedData.bytes[1];
  AKA_mark("lis===21###sois===593###eois===629###lif===13###soif===465###eoif===501###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::updateDashboard()");Can0.sendFrame(lastBrakeSpeedFrame);
}

/** Instrumented function CANProcessor::newVehicleData() */
bool CANProcessor::newVehicleData() /* << Aka begin of function bool CANProcessor::newVehicleData() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::newVehicleData()");AKA_fCall++;
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.newVehicleData.641.stub"

  AKA_mark("lis===25###sois===677###eois===698###lif===1###soif===41###eoif===62###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::newVehicleData()");bool newData = false;
  AKA_mark("lis===26###sois===702###eois===739###lif===2###soif===66###eoif===103###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::newVehicleData()");newData = newData || checkBus(&Can0);
  AKA_mark("lis===27###sois===743###eois===780###lif===3###soif===107###eoif===144###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::newVehicleData()");newData = newData || checkBus(&Can1);

  AKA_mark("lis===29###sois===786###eois===801###lif===5###soif===150###eoif===165###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::newVehicleData()");return newData;
}

/** Instrumented function CANProcessor::checkBus(CANRaw*) */
bool CANProcessor::checkBus(CANRaw *bus) /* << Aka begin of function bool CANProcessor::checkBus(CANRaw *bus) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::checkBus(CANRaw*)");AKA_fCall++;
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.checkBus.813.stub"

  AKA_mark("lis===33###sois===854###eois===870###lif===1###soif===46###eoif===62###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::checkBus(CANRaw*)");CAN_FRAME frame;
  if (AKA_mark("lis===34###sois===878###eois===898###lif===2###soif===70###eoif===90###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::checkBus(CANRaw*)") && (AKA_mark("lis===34###sois===878###eois===898###lif===2###soif===70###eoif===90###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::checkBus(CANRaw*)") && (bus->available() > 0))) {
    // digitalWrite(DS2, LOW);

    AKA_mark("lis===37###sois===941###eois===958###lif===5###soif===133###eoif===150###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::checkBus(CANRaw*)");bus->read(frame);
    AKA_mark("lis===38###sois===964###eois===991###lif===6###soif===156###eoif===183###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::checkBus(CANRaw*)");return processFrame(frame);
  }
else {
AKA_mark("lis===-34-###sois===-878-###eois===-87820-###lif===-2-###soif===-###eoif===-90-###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::checkBus(CANRaw*)");
}
  // digitalWrite(DS2, HIGH);
  AKA_mark("lis===41###sois===1031###eois===1044###lif===9###soif===223###eoif===236###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::checkBus(CANRaw*)");return false;
}

/** Instrumented function CANProcessor::processFrame(CAN_FRAME&) */
bool CANProcessor::processFrame(CAN_FRAME &frame) /* << Aka begin of function bool CANProcessor::processFrame(CAN_FRAME &frame) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");AKA_fCall++;
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.processFrame.1056.stub"

  AKA_mark("lis===45###sois===1106###eois===1127###lif===1###soif===55###eoif===76###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");bool newData = false;
  
  if (AKA_mark("lis===47###sois===1139###eois===1155###lif===3###soif===88###eoif===104###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===47###sois===1139###eois===1155###lif===3###soif===88###eoif===104###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (frame.id == 0xD0))) {
    // steering
    AKA_mark("lis===49###sois===1181###eois===1247###lif===5###soif===130###eoif===196###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");int16_t steering = frame.data.bytes[1] << 8 | frame.data.bytes[0];

    if (AKA_mark("lis===51###sois===1259###eois===1284###lif===7###soif===208###eoif===233###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===51###sois===1259###eois===1284###lif===7###soif===208###eoif===233###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (steering != pose.steering))) {
      AKA_mark("lis===52###sois===1295###eois===1310###lif===8###soif===244###eoif===259###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");newData = true;
      AKA_mark("lis===53###sois===1318###eois===1343###lif===9###soif===267###eoif===292###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");pose.steering = steering;
    }
else {
AKA_mark("lis===-51-###sois===-1259-###eois===-125925-###lif===-7-###soif===-###eoif===-233-###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");
}
  }
  else {
if (AKA_mark("lis===56###sois===1368###eois===1384###lif===12###soif===317###eoif===333###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===56###sois===1368###eois===1384###lif===12###soif===317###eoif===333###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (frame.id == 0xD1))) {
    AKA_mark("lis===57###sois===1393###eois===1421###lif===13###soif===342###eoif===370###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");lastBrakeSpeedFrame = frame;

    // brake pedal pressure
    AKA_mark("lis===60###sois===1458###eois===1495###lif===16###soif===407###eoif===444###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");uint8_t brakes = frame.data.bytes[2];

    if (AKA_mark("lis===62###sois===1507###eois===1528###lif===18###soif===456###eoif===477###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===62###sois===1507###eois===1528###lif===18###soif===456###eoif===477###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (brakes != pose.brakes))) {
      AKA_mark("lis===63###sois===1539###eois===1554###lif===19###soif===488###eoif===503###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");newData = true;
      AKA_mark("lis===64###sois===1562###eois===1583###lif===20###soif===511###eoif===532###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");pose.brakes = brakes;
    }
else {
AKA_mark("lis===-62-###sois===-1507-###eois===-150721-###lif===-18-###soif===-###eoif===-477-###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");
}
  }
  else {
if (AKA_mark("lis===67###sois===1608###eois===1625###lif===23###soif===557###eoif===574###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===67###sois===1608###eois===1625###lif===23###soif===557###eoif===574###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (frame.id == 0x140))) {
    // accelerator pedal position + clutch engaged / not
    AKA_mark("lis===69###sois===1692###eois===1734###lif===25###soif===641###eoif===683###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");uint8_t accelerator = frame.data.bytes[0];
    AKA_mark("lis===70###sois===1740###eois===1773###lif===26###soif===689###eoif===722###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");bool clutch = frame.data.bit[15];

    if (AKA_mark("lis===72###sois===1785###eois===1841###lif===28###soif===734###eoif===790###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && ((AKA_mark("lis===72###sois===1785###eois===1816###lif===28###soif===734###eoif===765###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (pose.accelerator != accelerator)) || (AKA_mark("lis===72###sois===1820###eois===1841###lif===28###soif===769###eoif===790###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (pose.clutch != clutch))))
      {
AKA_mark("lis===73###sois===1850###eois===1865###lif===29###soif===799###eoif===814###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");newData = true;
}

else {
AKA_mark("lis===-72-###sois===-1785-###eois===-178556-###lif===-28-###soif===-###eoif===-790-###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");
}
    
    AKA_mark("lis===75###sois===1877###eois===1908###lif===31###soif===826###eoif===857###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");pose.accelerator = accelerator;
    AKA_mark("lis===76###sois===1914###eois===1935###lif===32###soif===863###eoif===884###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");pose.clutch = clutch;
  }
  else {
if (AKA_mark("lis===78###sois===1953###eois===1970###lif===34###soif===902###eoif===919###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===78###sois===1953###eois===1970###lif===34###soif===902###eoif===919###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (frame.id == 0x141))) {
    AKA_mark("lis===79###sois===1979###eois===2009###lif===35###soif===928###eoif===958###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");lastTransmissionFrame = frame;
    AKA_mark("lis===80###sois===2015###eois===2057###lif===36###soif===964###eoif===1006###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");bool inGear = frame.data.bytes[5] == 0x80;

    if (AKA_mark("lis===82###sois===2069###eois===2090###lif===38###soif===1018###eoif===1039###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===82###sois===2069###eois===2090###lif===38###soif===1018###eoif===1039###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (pose.inGear != inGear))) {
      AKA_mark("lis===83###sois===2101###eois===2116###lif===39###soif===1050###eoif===1065###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");newData = true;
      AKA_mark("lis===84###sois===2124###eois===2145###lif===40###soif===1073###eoif===1094###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");pose.inGear = inGear;
      // SerialUSB.print("In gear: ");
      // SerialUSB.println(pose.inGear);
    }
else {
AKA_mark("lis===-82-###sois===-2069-###eois===-206921-###lif===-38-###soif===-###eoif===-1039-###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");
}
  }
  else {
if (AKA_mark("lis===89###sois===2252###eois===2269###lif===45###soif===1201###eoif===1218###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===89###sois===2252###eois===2269###lif===45###soif===1201###eoif===1218###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (frame.id == 0x144))) {
    // cruise control stalk (used for upshift / downshift)
    AKA_mark("lis===91###sois===2338###eois===2386###lif===47###soif===1287###eoif===1335###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");uint8_t cruiseControlStalk = frame.data.byte[0];

    AKA_mark("lis===93###sois===2394###eois===2436###lif===49###soif===1343###eoif===1385###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");bool upshift = cruiseControlStalk == 0xD0;
    AKA_mark("lis===94###sois===2442###eois===2486###lif===50###soif===1391###eoif===1435###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");bool downshift = cruiseControlStalk == 0xC8;
    // if (pose.upshift != upshift || pose.downshift != downshift) {
    //   pose.upshift = upshift;
    //   pose.downshift = downshift;
    //   newData = true;
    // }
  }
  else {
if (AKA_mark("lis===101###sois===2682###eois===2699###lif===57###soif===1631###eoif===1648###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===101###sois===2682###eois===2699###lif===57###soif===1631###eoif===1648###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (frame.id == 0x152))) {
    // e-brake engaged or not
    AKA_mark("lis===103###sois===2739###eois===2772###lif===59###soif===1688###eoif===1721###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");bool ebrake = frame.data.bit[51];

    if (AKA_mark("lis===105###sois===2784###eois===2805###lif===61###soif===1733###eoif===1754###ifc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (AKA_mark("lis===105###sois===2784###eois===2805###lif===61###soif===1733###eoif===1754###isc===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)") && (pose.ebrake != ebrake)))
      {
AKA_mark("lis===106###sois===2814###eois===2829###lif===62###soif===1763###eoif===1778###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");newData = true;
}

else {
AKA_mark("lis===-105-###sois===-2784-###eois===-278421-###lif===-61-###soif===-###eoif===-1754-###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");
}

    AKA_mark("lis===108###sois===2837###eois===2858###lif===64###soif===1786###eoif===1807###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");pose.ebrake = ebrake;
  }
else {
AKA_mark("lis===-101-###sois===-2682-###eois===-268217-###lif===-57-###soif===-###eoif===-1648-###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");
}
}

}

}

}

}


  AKA_mark("lis===111###sois===2869###eois===2884###lif===67###soif===1818###eoif===1833###ins===true###function===.\\outlandnish_fw-ghost-drive\\src\\CANProcessor.cpp\\CANProcessor::processFrame(CAN_FRAME&)");return newData;
}
#endif
