/*
  ShiftRegister74HC595.h - Library for easy control of the 74HC595 shift register.
  Created by Timo Denk (www.simsso.de), Nov 2014.
  Additional information are available on http://shiftregister.simsso.de/
  Released into the public domain.
  https://www.instructables.com/How-to-use-a-Shift-Register-Arduino-Tutorial/
  https://github.com/Simsso/ShiftRegister74HC595
  changes by Nicu FLORICA (niq_ro)
  v.0 - changed for animation for 16 leds (2 shift registers)
*/

#include <ShiftRegister74HC595.h>
#define DATA  11
#define CLK   12
#define LATCH  8
// parameters: <number of shift registers> (data pin, clock pin, latch pin)
ShiftRegister74HC595<2> sr(DATA, CLK, LATCH); 
byte k=0;
unsigned long pauza = 250;
unsigned long timp;

void setup() { 
  sr.setAllLow(); // set all pins LOW
  delay(500); 
  k =0;
}

void loop() {

  if (millis() - timp > pauza)
  {
    sr.set(k%16, 0);
    k++;
    sr.set(k%16,1);
    timp = millis();
  }

  
  delay(1);
} // end main loop
