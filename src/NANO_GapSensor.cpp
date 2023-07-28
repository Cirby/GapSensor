// Arduino GapSensor Library v1.0.0 - A simple interface for GAP sensors.
// https://github.com/Cirby/GapSensor
// Copyright (c) 2023 Attila Toth <cirbolya@gmail.com> - ??? License


#include <NANO_GapSensor.h>

namespace NANO {

    /// @brief Initialize GAP sensor input ports
    /// @param pinIN1 GAP sensor 1
    /// @param pinIN2 GAP sensor 2
    GapSensor::GapSensor(uint8_t pinIN1, uint8_t pinIN2) {
        _pinIN1 = pinIN1;
        _pinIN2 = pinIN2;
        pinMode(_pinIN1, INPUT);
        pinMode(_pinIN2, INPUT);
    }

    /// @brief Read GAP sensors and calculate status
    /// @return Calculated status
    GapSensor::GapStatus GapSensor::getValue() {
        _value1 = analogRead(_pinIN1);
        _value2 = analogRead(_pinIN2);
        _status = status9999;
        
        return _status;
    }

} // namespace NANO
