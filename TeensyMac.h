// Spencer Lommel
// TeensyMAC v1.2.0
// Apr. 8th 2025
// Updated Single header version

// No warranty, no license, use this code for whatever, enjoy =D

#ifndef TEENSY_MAC_H
#define TEENSY_MAC_H
#include <Arduino.h>
#if defined(__MK20DX128__) || defined(__MK20DX256__) || defined(__IMXRT1062__)
#define TEENSY_HAS_MAC
#endif
#ifdef TEENSY_HAS_MAC
class TeensyMAC {
public:
    static uint8_t* getMAC() {
        static uint8_t mac[6];
        #if defined(__MK20DX128__) || defined(__MK20DX256__)
        // Teensy 3.0 and 3.1/3.2 use the unique ID registers
        uint8_t *uid = (uint8_t *)0x40048058; // SIM_UIDMH
        mac[0] = 0x02;
        mac[1] = uid[0];
        mac[2] = uid[1];
        mac[3] = uid[2];
        mac[4] = uid[3];
        mac[5] = uid[4];
        #elif defined(__IMXRT1062__)
        // Generate MAC from UID (CFG0/CFG1)
        uint32_t uid_high = HW_OCOTP_CFG0;
        uint32_t uid_low  = HW_OCOTP_CFG1;
        mac[0] = 0x02; // Locally administered MAC
        mac[1] = (uid_high >> 24) & 0xFF;
        mac[2] = (uid_high >> 16) & 0xFF;
        mac[3] = (uid_low >> 24) & 0xFF;
        mac[4] = (uid_low >> 16) & 0xFF;
        mac[5] = (uid_low >> 8) & 0xFF;
       #endif
       return mac;
   }
   static String getMACString() {
       uint8_t* mac = getMAC();
       char buffer[18];
       snprintf(buffer, sizeof(buffer), "%02X:%02X:%02X:%02X:%02X:%02X",
                mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
       return String(buffer);
   }
};
#else
#error "This Teensy board is not supported by TeensyMAC."
#endif // TEENSY_HAS_MAC
#endif // TEENSY_MAC_H
