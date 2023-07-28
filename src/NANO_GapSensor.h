// Arduino GapSensor Library v1.0.0 - A simple interface for GAP sensors.
// https://github.com/Cirby/GapSensor
// Copyright (c) 2023 Attila Toth <cirbolya@gmail.com> - ??? License


#ifndef GAP_SENSOR
#define GAP_SENSOR

#include <Arduino.h>

namespace NANO {
  class GapSensor {
    public:
      typedef enum {     // (pin2_címke * 8) + (pin2_hordozó * 4) + (pin1_címke * 2) + (pin1_hordozó)
        status0000 = 0,  // Mindkettő üres
        status0001 = 1,  // Befutó hordozó
        status0010 = 2,  // Error
        status0011 = 3,  // Befutó hordozó címkével
        status0100 = 4,  // Kifutó hordozó
        status0101 = 5,  // Mindkettő hordozó
        status0110 = 6,  // Error
        status0111 = 7,  // Mindkettő hordozó, befutó címkével
        status1000 = 8,  // Error
        status1001 = 9,  // Error
        status1010 = 10, // Error
        status1011 = 11, // Error
        status1100 = 12, // Kifutó hordozó címkével
        status1101 = 13, // Mindkettő hordozó, kifutó címkével
        status1110 = 14, // Error
        status1111 = 15, // Mindkettő hordozó, mindkettő címkével
        status9999 = 16  // Error
      } GapStatus;

      GapSensor(uint8_t pinIN1, uint8_t pinIN2);
      GapStatus getValue();
    
    private:
      uint8_t _pinIN1;
      uint8_t _pinIN2;
      GapStatus _status;
      uint8_t _threshold_1_00;
      uint8_t _threshold_1_01;
      uint8_t _threshold_1_11;
      uint8_t _threshold_2_00;
      uint8_t _threshold_2_01;
      uint8_t _threshold_2_11;
      int _value1;
      int _value2;

  }; // class GapSensor
} // namespace NANO

#endif
