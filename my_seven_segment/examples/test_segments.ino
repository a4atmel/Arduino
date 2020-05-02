// this is an example of using MyTimer Library
#define debug(str) Serial.println(str)
#include <my_seven_segment.h>

my_seven_segment segment1(0,1,2,3,4,5,6,7,"CA"); // ledA to ledDP respectivly, type is CC:Com Cathode, or CA:Comon annode.

void setup() {
segment1.begin();
}

void loop() {
   segment1.display("ledA"); // (ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledH, ledDP  ) all leds can be illuminated alone.
   delay(1000);
   segment1.display("ledB"); // (ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledH, ledDP  ) all leds can be illuminated alone.
   delay(1000);
   segment1.display("ledC"); // (ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledH, ledDP  ) all leds can be illuminated alone.
   delay(1000);
   segment1.display("ledD"); // (ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledH, ledDP  ) all leds can be illuminated alone.
   delay(1000);
   segment1.display("ledE"); // (ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledH, ledDP  ) all leds can be illuminated alone.
   delay(1000);
   segment1.display("ledF"); // (ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledH, ledDP  ) all leds can be illuminated alone.
   delay(1000);
   segment1.display("ledG"); // (ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledH, ledDP  ) all leds can be illuminated alone.
   delay(1000);
   segment1.display("ledDP"); // (ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledH, ledDP  ) all leds can be illuminated alone.
   delay(1000);
}
