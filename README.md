# Arduino-Button

This library implements any physical button plugged to the Arduino board. I modelled it like an object where the state can retrieved using the following boolean method :

- **_isPressed()_**;

**Note #1** : the button must be plugged to the Arduino board using a pull-up resistor (10K Ohm).

**Note #2** : to prevent any switch debouncing problem during the reading of the button state, I used the source code located at https://www.arduino.cc/en/tutorial/debounce .
