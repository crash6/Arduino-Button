/*
 * Button.h - Library used to model a button connected to the Arduino board 
 * Created by crash6, February 22, 2019.
 * Released into the public domain
 */

 /*
  * Note : the button should be plugged to the Arduino board using a pull-up resistor (10k Ohm)
  */

#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button{
  
  //public members
  public:
    Button(int pin);
    bool isPressed();    
    int  getPin();

  //private members
  private:
    int  _pin;                    
    
    //The following private variables are used to fix possible button debouncing problems
    int _lastButtonState;
    int _buttonState;
    unsigned long _debounceDelay;
    unsigned long _lastDebounceTime;
};

#endif
