/* 
 * Copyright (c) 2019 Christophe Rubeck.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as   
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <ChristuxUtils.h>

unsigned long startTime = millis();
bool stop = false;
bool resume = false;

/* 
 * Defines blinking led
 */
BlinkLed bl = BlinkLed(LED_BUILTIN,1000);

/*
 * Setup
 */
void setup() {
  bl.setup();
}

/*
 * Main loop
 */
void loop() {
  
  /* 
   * Blinks built-in led
   */
  bl.handle();

  // Stop once after 5s
  if(!stop && millis() > startTime + 5000) {
    stop = true;
    bl.stop();
  }

  // Resume once after 10s
  if(!resume && millis() > startTime + 10000) {
    resume = true;
    bl.resume();
  }
}
