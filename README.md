# Description
This is a cross platform library aimed towards the [Teensy series microcontrollers](https://www.pjrc.com/) to get the MAC address of them easily.

# Board Support
This library supports the following boards:
- Teensy 4.0
- Teensy 3.1
- Teensy 3.0


I don't have any of the other boards to test on so I cannot guarantee support for those. If someone would like to donate me one I'd be happy to add support here =D

## Usage
Here's a super simple C++ file that shows how to use this library
```c++
#include "TeensyMAC.h"

// This is a simple function that prints out all of the bytes from the MAC address.
// It esentially works the same way TeensyMAC::getMACString() does
void printMACBytes(const uint8_t mac[6])
{
  Serial.print("MAC Bytes: ");
  for (int i = 0; i < 6; i++)
  {
    if (i > 0)
      Serial.print(":");
    if (mac[i] < 16)
      Serial.print("0");
    Serial.print(mac[i], HEX);
  }
  Serial.println();
}

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    delay(100); // Wait for serial connection
  Serial.println("=== TeensyMAC Test ===");
  // Get MAC string
  String macStr = TeensyMAC::getMACString();
  Serial.print("MAC String: ");
  Serial.println(macStr);
  // Get MAC bytes
  uint8_t mac[6];
  uint8_t *ptr = TeensyMAC::getMAC();
  for (int i = 0; i < 6; i++)
  {
    mac[i] = ptr[i]; // copy each byte
  }
  // Print copied MAC bytes
  printMACBytes(mac);
}
void loop()
{
  // Nothing in the loop
}
```

# Notice a bug?
Open a GitHub issue! I developed this library for a work project so I'd like to actively maintain it