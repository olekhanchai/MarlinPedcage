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
#include "../../feature/ADS1115.h"
#include "../gcode.h"
#include <Wire.h>
  /**
   * P050: Query current oxygen value.
   */

ADS1115 adc0(ADS1115_DEFAULT_ADDRESS);
double o2_gain = 0.43;
double o2_opset = 0.0;

void GcodeSuite::P50() {
    Wire.begin();  // join I2C bus
    adc0.initialize(); // initialize ADS1115 16 bit A/D chip

    if(!adc0.testConnection()) SERIAL_ECHO_MSG("ADS1115 connection failed");
      
    // To get output from this method, you'll need to turn on the 
    //#define ADS1115_SERIAL_DEBUG // in the ADS1115.h file
    adc0.showConfigRegister();
    
    // We're going to do continuous sampling
    adc0.setMode(ADS1115_MODE_CONTINUOUS); 

     // Set the gain (PGA) +/- 1.024v
    adc0.setGain(ADS1115_PGA_2P048);   

    // The below method sets the mux and gets a reading.
    int sensorOneCounts=adc0.getConversionP0N1();  // counts up to 16-bits  

    // To turn the counts into a voltage, we can use
    SERIAL_CHAR('V');
    SERIAL_CHAR(':');
    SERIAL_DECIMAL(sensorOneCounts*adc0.getMvPerCount());    
    SERIAL_CHAR(' ');      
    SERIAL_CHAR('O');
    SERIAL_CHAR(':');
    SERIAL_DECIMAL((sensorOneCounts*adc0.getMvPerCount()*o2_gain)+o2_opset);    
    SERIAL_EOL();
}
