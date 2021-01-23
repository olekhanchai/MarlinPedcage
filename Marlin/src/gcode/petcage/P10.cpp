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
   * P10: Set Array of Relay on/off
   */
void GcodeSuite::P10() {
  int relay[] = {RELAY_1_PIN,RELAY_2_PIN,RELAY_3_PIN,RELAY_4_PIN,RELAY_5_PIN,RELAY_6_PIN,RELAY_7_PIN,RELAY_8_PIN};
  int pin = 1;//P1_30;
  int pin_status = 0;
  if (parser.seenval('R')) pin = parser.value_int() - 1;
  if (pin < 0 || pin > 7 ) {SERIAL_ECHO_MSG("Invalid relay value!");return;}
  if (parser.seenval('S')) pin_status = parser.value_int();
  if (pin_status > 1) pin_status = 1;
  pinMode(relay[pin], OUTPUT);
  extDigitalWrite(relay[pin], pin_status);
}
