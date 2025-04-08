// Spencer Lommel
// Dec. 16th 2024
// This only gets the Mac Address for the Teensy 4.0 (maybe higher aswell?)
// If you need to get Mac of Teensy below 4.0 please use TeensyMac3.cpp

#include "TeensyMac.h"
#include <imxrt.h> // Access Teensy 4.0 hardware UID registers

void TeensyMAC::getMAC(uint8_t mac[6]) {
  uint32_t uid_high = HW_OCOTP_CFG0; // Upper 32-bits of UID
  uint32_t uid_low = HW_OCOTP_CFG1;  // Lower 32-bits of UID

  mac[0] = 0x02;
  mac[1] = (uid_high >> 24) & 0xFF;
  mac[2] = (uid_high >> 16) & 0xFF;
  mac[3] = (uid_low >> 24) & 0xFF;
  mac[4] = (uid_low >> 16) & 0xFF;
  mac[5] = (uid_low >> 8) & 0xFF;
}

String TeensyMAC::getMACString() {
  uint8_t mac[6];
  getMAC(mac);

  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X", mac[0],
           mac[1], mac[2], mac[3], mac[4], mac[5]);

  return String(macStr);
}
