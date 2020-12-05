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
 * P003: Turn on RGB Led
 */
void GcodeSuite::P3() {
  int pin_index = 1;
  int pin_status = 0;
  const pin_t pin = GET_PIN_MAP_PIN(pin_index);
  pinMode(pin, OUTPUT);
  analogWrite(pin, 255);
}

/**
 * P004: Turn off RGB Led
 */
void GcodeSuite::P4() {
  int pin_index = 0;
  int pin_status = 0;  
  const pin_t pin = GET_PIN_MAP_PIN(pin_index);
  pinMode(pin, OUTPUT);
  analogWrite(pin, 0);
}
