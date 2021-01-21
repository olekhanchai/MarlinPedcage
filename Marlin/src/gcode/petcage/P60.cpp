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
#include "../../feature/WS2812B.h"
#include "../gcode.h"

  /**
   * P60: NeoPixel Control
   */
WS2812B strip = WS2812B(16);

void GcodeSuite::P60() {
  int red = 0;
  int green = 0;
  int blue = 0;
  int total = 0;
  if (parser.seenval('R')) red = parser.value_int();
  if (parser.seenval('G')) green = parser.value_int();
  if (parser.seenval('B')) blue = parser.value_int();  
  if (parser.seenval('N')) total = parser.value_int();  

  if ( (red < 0 || red > 255 ) || (green < 0 || green > 255) || (blue < 0 || blue > 255 )) {SERIAL_ECHO_MSG("Invalid color value!");return;}

  strip.begin();

  for(int i=0;i<total;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(red,green,blue)); // Moderately bright green color.
    strip.show(); // This sends the updated pixel color to the hardware.
  }
}
