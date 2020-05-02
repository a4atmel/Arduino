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
   segment1.display(2); //integer from 0 to 8;
   delay(1000);
   segment1.display(3); //integer from 0 to 8;
   delay(1000);
   segment1.display(4); //integer from 0 to 8;
   delay(1000);
   segment1.display(5); //integer from 0 to 8;
   delay(1000);
   segment1.display(6); //integer from 0 to 8;
   delay(1000);
   segment1.display(7); //integer from 0 to 8;
   delay(1000);
   segment1.display(8); //integer from 0 to 8;
   delay(1000);
}
