/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"
#include "../gcode.h"

/**
 * P011: Turn on Relay1
 */
void GcodeSuite::P11() {
  int pin_status = 0;
  const pin_t pin = E1_STEP_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P012: Turn off Relay1
 */
void GcodeSuite::P12() {
  int pin_status = 1;  
  const pin_t pin = E1_STEP_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P013: Turn on Relay2
 */
void GcodeSuite::P13() {
  int pin_status = 0;
  const pin_t pin = E1_ENABLE_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P014: Turn off Relay2
 */
void GcodeSuite::P14() {
  int pin_status = 1;
  const pin_t pin = E1_ENABLE_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P015: Turn on Relay3
 */
void GcodeSuite::P15() {
  int pin_status = 0;
  const pin_t pin = E0_DIR_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P016: Turn off Relay3
 */
void GcodeSuite::P16() {
  int pin_status = 1;
  const pin_t pin = E0_DIR_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P017: Turn on Relay4
 */
void GcodeSuite::P17() {
  int pin_index = 0;
  int pin_status = 0;
  const pin_t pin = GET_PIN_MAP_PIN(pin_index);
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P018: Turn off Relay4
 */
void GcodeSuite::P18() {
  int pin_index = 0;
  int pin_status = 0;  
  const pin_t pin = GET_PIN_MAP_PIN(pin_index);
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P019: Turn on Relay5
 */
void GcodeSuite::P19() {
  int pin_index = 0;
  int pin_status = 0;
  const pin_t pin = GET_PIN_MAP_PIN(pin_index);
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P020: Turn off Relay5
 */
void GcodeSuite::P20() {
  int pin_index = 0;
  int pin_status = 0;  
  const pin_t pin = GET_PIN_MAP_PIN(pin_index);
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P021: Turn on Relay6
 */
void GcodeSuite::P21() {
  int pin_status = 0;
  const pin_t pin = E0_DIR_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P022: Turn off Relay6
 */
void GcodeSuite::P22() {
  int pin_status = 1;
  const pin_t pin = E0_DIR_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P023: Turn on Relay7
 */
void GcodeSuite::P23() {
  int pin_status = 0;
  const pin_t pin = E0_STEP_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P024: Turn off Relay7
 */
void GcodeSuite::P24() {
  int pin_status = 1;
  const pin_t pin = E0_STEP_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P025: Turn on Relay7
 */
void GcodeSuite::P25() {
  int pin_status = 0;
  const pin_t pin = E0_ENABLE_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * v: Turn off Relay7
 */
void GcodeSuite::P26() {
  int pin_status = 1;
  const pin_t pin = E0_ENABLE_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}
