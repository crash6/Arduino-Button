/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  - Note: On most Arduino boards, there is already an LED on the board connected
    to pin 13, so you don't need any extra components for this example.

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/

#include "Arduino.h"
#include "Button.h"

#define INITIAL_STATE       LOW
#define DEBOUNCE_DELAY      100      //50ms

/**
    The code used here to fix the the debounce button problem, is located at http://www.arduino.cc/en/tutorial/debounce 
*/

//Class constructor
Button::Button(int pin){
  _pin = pin;
  pinMode(_pin, INPUT);  //I don't check if the pin number received is valid

  //Followinf variables are used to fix the possible button debouncing issue
  _debounceDelay = DEBOUNCE_DELAY;
  _lastDebounceTime = 0;
  _lastButtonState = INITIAL_STATE;
  
}

//Returns true if the button is pressed, false otherwise
bool Button::isPressed(){
   bool retVal = false;
   
   int reading = digitalRead(_pin);

   if(reading != _lastButtonState){
      _lastDebounceTime = millis();
   }

   if((millis() - _lastDebounceTime) > _debounceDelay){
       
       if(reading != _buttonState){
          _buttonState = reading;
       
          if(_buttonState == HIGH){
            retVal = true;
          }
       } 
   }

   _lastButtonState = reading;

   return retVal;   
 }

//Returns the pin number to which the button is connected
int Button::getPin(){
  return _pin;  
}
