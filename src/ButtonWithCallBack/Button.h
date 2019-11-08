/* 
 * Copyright (c) 2017 Christophe Rubeck.
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

#ifndef Button_h
#define Button_h

#include "Arduino.h"

/*
 * Defines pointer to function type
 */
typedef void (*buttonActionFunction) ();

class Button
{  
  protected:
    const unsigned int _buttonPin;
    buttonActionFunction _callbackOnPush;
    buttonActionFunction _callbackOnRelease;
    buttonActionFunction _callbackOnChange;
    int _buttonState;
    int _lastButtonState;
    unsigned long _pushTime;
    const int _pushDelay = 200; // millis
    
  public:
    Button(unsigned int ledPin, buttonActionFunction callbackFunction);
    Button(unsigned int ledPin);
    void setup() const;
    void setOnPush(buttonActionFunction callbackOnPush);
    void setOnRelease(buttonActionFunction callbackOnRelease);
    void setOnChange(buttonActionFunction callbackOnChange);
    void handle();
};

#endif
