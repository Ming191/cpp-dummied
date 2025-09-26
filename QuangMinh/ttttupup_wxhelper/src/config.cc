#include "pch.h"
#include "config.h"

namespace wxhelper {
Config::Config(/* args */) {}

Config::~Config() {}

void Config::Initialize() {
  port_ = GetPrivateProfileIntA("config", "Port", 19088, "./config.ini");
}
int Config::GetPort() { return port_; }

}  // namespace wxhelper