// Spencer Lommel
// Dec. 16th 2024
// Header for TeensyMac4.cpp & TeensyMac3.cpp

#ifndef TEENSYMAC_H
#define TEENSYMAC_H

#include <Arduino.h>

class TeensyMAC {
public:
  static void getMAC(uint8_t mac[6]); // Get MAC address as an array
  static String getMACString();       // Get MAC address as a string
};

#endif // TEENSYMAC_H
