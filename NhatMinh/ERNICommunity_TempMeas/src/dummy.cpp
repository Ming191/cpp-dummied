#include "Adafruit_MCP9808.h"
#include "Arduino.h"
#include "DbgCliCommand.h"
#include "DbgCliNode.h"
#include "DbgCliTopic.h"
#include "DbgPrintConsole.h"
#include "DbgTraceContext.h"
#include "DbgTraceLevel.h"
#include "DbgTraceOut.h"
#include "DbgTracePort.h"
#include "MyTempMonAdapter.h"
#include "ProductDebug.h"
#include "RamUtils.h"
#include "SerialCommand.h"
#include "TempMon.h"
#include "ThingSpeak.h"
#include "Timer.h"
#include "TM1638.h"
#include "WiFiClient.h"
#include "Wire.h"
#include <string>

// Arduino.h
DummySerialClass Serial;
DummyWiFiClass WiFi;

// DummySerialClass implementations
void DummySerialClass::begin(int) {}
void DummySerialClass::print(const char* s) {}
void DummySerialClass::print(unsigned int n) {}
void DummySerialClass::print(float f, int) {}
void DummySerialClass::println() {}
void DummySerialClass::println(const char* s) {}
void DummySerialClass::println(unsigned int n) {}
void DummySerialClass::println(float f, int) {}
void DummySerialClass::println(std::string s) {}

// DummyWiFiClass implementations
std::string DummyWiFiClass::macAddress() {}
bool DummyWiFiClass::getAutoConnect() {}
int DummyWiFiClass::status(){}
void DummyWiFiClass::disconnect(bool) {}
void DummyWiFiClass::begin(const char*, const char*) {}

// Adafruit_MCP9808.h
Adafruit_MCP9808::Adafruit_MCP9808() {}
bool Adafruit_MCP9808::begin(int) {}
float Adafruit_MCP9808::readTempC() {}

// DbgCliCommand.h
DbgCli_Command::DbgCli_Command(DbgCli_Topic*, const char*, const char*) {}
void DbgCli_Command::execute(unsigned int, const char**, unsigned int) {}
const char* DbgCli_Command::getHelpText() { return ""; }

// DbgCliNode.h
void DbgCli_Node::AssignRootNode(DbgCli_Node*) {}
DbgCli_Node* DbgCli_Node::RootNode() {}
void DbgCli_Node::execute(unsigned int, const char**, unsigned int) {}

// DbgCliTopic.h
DbgCli_Topic::DbgCli_Topic(DbgCli_Node*, const char*, const char*) {}

// DbgPrintConsole.h
DbgPrint_Console::DbgPrint_Console() {}

// DbgTraceContext.h
DbgTrace_Context::DbgTrace_Context(DbgCli_Topic*) {}
DbgTrace_Context* DbgTrace_Context::getContext() {}

// DbgTraceOut.h
DbgTrace_Out::DbgTrace_Out(DbgTrace_Context*, const char*, DbgPrint_Console*) {}

// DbgTracePort.h
DbgTrace_Port::DbgTrace_Port(const char*, int) {}

// RamUtils.h
long RamUtils::getFreeRam() {}

// SerialCommand.h
SerialCommand::SerialCommand() {}
void SerialCommand::addCommand(const char*, void(*)()) {}
void SerialCommand::setDefaultHandler(void(*)(const char *)) {}
char* SerialCommand::next() {}

// TempMon.h
ITempMonAdapter::~ITempMonAdapter() {}
void ITempMonAdapter::NotifyTempChg(float temp) {}

// ThingSpeak.h
ThingSpeakClass ThingSpeak;
void ThingSpeakClass::setField(int, float) {}
int ThingSpeakClass::writeFields(int, const char*) {}

// Timer.h
TimerAdapter::~TimerAdapter() {}
void TimerAdapter::timeExpired() {}
Timer::Timer(TimerAdapter*, RecurringType, unsigned long) {}

// TM1638.h
void TM1638::setDisplayToString(const char*, word) {}

// WiFiClient.h
WiFiClient::WiFiClient() {}

// Wire.h
WireClass Wire;
void WireClass::begin(int, int) {} 