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

#include "Button.h"

/*
 * Constructors
 */
Button::Button(unsigned int buttonPin, buttonActionFunction callbackOnPush):
  _buttonPin(buttonPin),
  _callbackOnPush(callbackOnPush),
  _callbackOnRelease(nullptr),
  _callbackOnChange(nullptr),
  _buttonState(HIGH),
  _lastButtonState(HIGH),
  _pushTime(0)
{}

Button::Button(unsigned int buttonPin): Button(buttonPin, nullptr)
{}

/*
 * Setup
 */
void Button::setup() const {
  pinMode(_buttonPin, INPUT_PULLUP);
}

void Button::setOnPush(buttonActionFunction callbackOnPush) {
  _callbackOnPush = callbackOnPush;
}

void Button::setOnRelease(buttonActionFunction callbackOnRelease) {
  _callbackOnRelease = callbackOnRelease;
}

void Button::setOnChange(buttonActionFunction callbackOnChange) {
  _callbackOnChange = callbackOnChange;
}

/*
 * Listen to button push and call _callbackFunction
 */
void Button::handle() {

  unsigned long currTime = millis();
  int state = digitalRead(_buttonPin);
  
  if(currTime > _pushTime) {

    if (state != _lastButtonState) {    
      _pushTime = currTime + _pushDelay;
      _lastButtonState = state;
    }
    else {
      
      if(state != _buttonState) {
        _buttonState = state;

        if(_callbackOnChange != nullptr) {
            _callbackOnChange();
          }

        if(_buttonState == LOW) {
          if(_callbackOnPush != nullptr) {
            _callbackOnPush();
          }
        }

        if(_buttonState == HIGH) {
          if(_callbackOnRelease != nullptr) {
            _callbackOnRelease();
          }    
        }
      }
    }
  }
}
