/*
  ShiftRegister74HC595.h - Library for easy control of the 74HC595 shift register.
  Created by Timo Denk (www.simsso.de), Nov 2014.
  Additional information are available on http://shiftregister.simsso.de/
  Released into the public domain.
  https://www.instructables.com/How-to-use-a-Shift-Register-Arduino-Tutorial/
  https://github.com/Simsso/ShiftRegister74HC595
  changes by Nicu FLORICA (niq_ro)
  v.0 - changed for animation for 16 leds (2 shift registers)
  v.1 - added buttons for stop, play, rew and ffd
*/

#include <ShiftRegister74HC595.h>
#define DATA  11
#define CLK   12
#define LATCH  8
#define BUT1   5
#define BUT2   4
#define BUT3   3
#define BUT4   2

// parameters: <number of shift registers> (data pin, clock pin, latch pin)
ShiftRegister74HC595<2> sr(DATA, CLK, LATCH); 
byte k = 0;
int j = 0;
byte mod = 1;
unsigned long pauza = 250;
unsigned long pauza1 = 250;
unsigned long pauza2 = 50;
unsigned long timp;

void setup() {
  pinMode(BUT1, INPUT);
  digitalWrite(BUT1, HIGH);
  pinMode(BUT2, INPUT);
  digitalWrite(BUT2, HIGH);
  pinMode(BUT3, INPUT);
  digitalWrite(BUT3, HIGH);
  pinMode(BUT4, INPUT);
  digitalWrite(BUT4, HIGH);

   
  sr.setAllLow(); // set all pins LOW
  delay(500); 
  k =0;
}

void loop() {
  if (millis() - timp > pauza)
  {
    sr.set(k%16, 0);
    k = k + j;
    sr.set(k%16,1);
    timp = millis();
  }

  if (digitalRead(BUT1) == LOW)
  {
      mod = 1;  // stop
      pauza = pauza1;
      j = 0;
  }
  if (digitalRead(BUT2) == LOW)
  {
      mod = 2;   // rew (REWIND)
      pauza = pauza2;
      j = -1;
  }    
  if (digitalRead(BUT3) == LOW)
  {
      mod = 3;   // play
      pauza = pauza1;
      j = 1;
  }
  
  if (digitalRead(BUT4) == LOW)
  {
      mod = 4;   // ffw (FAST FORWARD)
      pauza = pauza2;
      j = 1;
  }

  
  delay(1);
} // end main loop
