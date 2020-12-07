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
#include "../../feature/LMP91000.h"
#include "../gcode.h"
#include <Wire.h>
  /**
   * P027: Query current all sensor.
   */

void GcodeSuite::P30() {

      LMP91000 lmp91000;

      SERIAL_ECHO_MSG("LMP91000 Test");
      Wire.begin();
      
      // initialize the slot select pins to "not selected"
      pinMode(7, OUTPUT);  digitalWrite(7, LOW);
      pinMode(9, OUTPUT);  digitalWrite(9, LOW);
      pinMode(10, OUTPUT); digitalWrite(10, LOW);      
      digitalWrite(9, HIGH); // select CO
      
      // settings for CO
      uint8_t res = lmp91000.configure( 
            LMP91000_TIA_GAIN_350K | LMP91000_RLOAD_10OHM,
            LMP91000_REF_SOURCE_EXT | LMP91000_INT_Z_20PCT 
                  | LMP91000_BIAS_SIGN_POS | LMP91000_BIAS_1PCT,
            LMP91000_FET_SHORT_DISABLED | LMP91000_OP_MODE_AMPEROMETRIC                  
      );
      char buffer[20];
      SERIAL_ECHO_MSG("Config Result: ");
      SERIAL_ECHO_MSG("STATUS: ");
      itoa(lmp91000.read(LMP91000_STATUS_REG), buffer, 16);
      SERIAL_CHAR(buffer);
      SERIAL_CHAR('-');
      SERIAL_DECIMAL(sizeof(buffer)/sizeof(buffer[0]));
      SERIAL_ECHO_MSG("TIACN: ");
      itoa(lmp91000.read(LMP91000_TIACN_REG), buffer, 16);
      SERIAL_CHAR(buffer);
      SERIAL_CHAR('-');
      SERIAL_DECIMAL(sizeof(buffer)/sizeof(buffer[0]));      
      SERIAL_ECHO_MSG("REFCN: ");
      itoa(lmp91000.read(LMP91000_REFCN_REG), buffer, 16);
      SERIAL_CHAR(buffer);
      SERIAL_CHAR('-');
      SERIAL_DECIMAL(sizeof(buffer)/sizeof(buffer[0]));
      SERIAL_ECHO_MSG("MODECN: ");
      itoa(lmp91000.read(LMP91000_MODECN_REG), buffer, 16);  
      SERIAL_CHAR(buffer);
      SERIAL_CHAR('-');
      SERIAL_DECIMAL(sizeof(buffer)/sizeof(buffer[0]));      
}
