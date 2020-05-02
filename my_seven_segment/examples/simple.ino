// this is an example of using MyTimer Library
#define debug(str) Serial.println(str)
#include <my_seven_segment.h>

my_seven_segment segment1(0,1,2,3,4,5,6,7,"CA"); // ledA to ledDP respectivly, type is CC:Com Cathode, or CA:Comon annode.

void setup() {
segment1.begin();
}

void loop() {
   segment1.display(1); //integer from 0 to 8;
   delay(1000);
   segment1.display("ledA"); // (ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledH, ledDP  ) all leds can be illuminated alone.
   delay(1000);
   segment1.display("F");  // also letters A, C, E, F, U, H
   delay(1000);
   segment1.clear();
   delay(1000);
}
