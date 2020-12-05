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
 * P001: Turn on UV Light
 */
void GcodeSuite::P1() {
  int pin_status = 0;
  const pin_t pin = E1_DIR_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}

/**
 * P002: Turn off UV Light
 */
void GcodeSuite::P2() {
  int pin_status = 1;
  const pin_t pin = E1_DIR_PIN;
  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
}
