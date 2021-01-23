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
   * P070: Query current co-zir co2 sensor.
   */
void GcodeSuite::P70() {
  int incomingByte = 0;
  char buffers[5];
  char tempbuff[100]; 
  char humid[10];
  char temper[10];
  char co2[10];
  float humidVal = 0.0;
  float temperVal = 0.0;
  int co2Val = 0;     
 
  Serial1.print("Q\r\n");
  strcpy(tempbuff, "");
  SERIAL_ECHOPGM(STR_OK);  
  while(Serial1.available() > 0) {
      incomingByte = Serial1.read();
      sprintf(buffers,"%c",incomingByte);
      sprintf(tempbuff,"%s%s",tempbuff,buffers);  
  }
  char * pch;
  pch = strtok (tempbuff," ");
  int counter = 0;
  while (pch != NULL)
  {
    sprintf (buffers,"%s\n",pch);   
    if (counter == 1) {
      strcpy(humid, buffers);
      humidVal = (atof(humid)-0)/10.0;
    } 
    if (counter == 3) {
      strcpy(temper, buffers);
      temperVal = (atof(temper)-1000)/10.0;      
    }
    if (counter == 5) {
      strcpy(co2, buffers);
      co2Val = atoi(co2) * 10;
    }
    pch = strtok (NULL, " ");
    counter++;
  }
  SERIAL_CHAR(' ');
  SERIAL_CHAR('H');   
  SERIAL_CHAR(':');   
  SERIAL_DECIMAL(humidVal);
//  SERIAL_DECIMAL(abs(rand()*100));
  SERIAL_CHAR(' ');
  SERIAL_CHAR('T');   
  SERIAL_CHAR(':');   
  SERIAL_DECIMAL(temperVal);
//  SERIAL_DECIMAL(abs(rand()*100));
  SERIAL_CHAR(' ');
  SERIAL_CHAR('C');   
  SERIAL_CHAR(':');   
  SERIAL_DECIMAL(co2Val);
  SERIAL_EOL();
//  SERIAL_DECIMAL(abs(rand()*10000));
  if (humidVal == 0 && temperVal == 0 && co2Val == 0) {
    // if no valid value re-initial sensor.
    Serial1.print("G\r\n");
    Serial1.print("M 04164\r\n");
    Serial1.print("K 2\r\n"); 
  }
}
