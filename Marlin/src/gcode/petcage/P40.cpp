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
#include "../../feature/SparkFun_SCD30_Arduino_Library.h"
#include "../gcode.h"
#include <Wire.h>
  /**
   * P040: Query current all sensors.
   */

void GcodeSuite::P40() {

      SCD30 airSensor;
      Wire.begin();

      if (airSensor.begin() == false)
      {
            SERIAL_ECHO_MSG("error:Air sensor not detected. Please check wiring. Freezing...");
      }
      
      if (airSensor.dataAvailable()) {
            SERIAL_CHAR('Z');
            SERIAL_CHAR(':');
            SERIAL_DECIMAL(airSensor.getCO2());
            SERIAL_CHAR(' ');
            SERIAL_CHAR('T');
            SERIAL_CHAR(':');
            SERIAL_DECIMAL(airSensor.getTemperature());
            SERIAL_CHAR(' ');
            SERIAL_CHAR('H');
            SERIAL_CHAR(':');
            SERIAL_DECIMAL(airSensor.getHumidity());
            SERIAL_CHAR(' ');
            SERIAL_EOL();
      }
}
