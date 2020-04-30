// this is an example of using MyTimer Library
#define debug(str) Serial.println(str)
#include <MyTimer.h>
MyTimer t1;
MyTimer t2;

void setup() {
t1.reset();
t2.reset();
Serial.begin(9600);
debug("");
}

void loop() {
   t1.start(6000);  // time is 600 millis
   t2.start(7000);
   if(!t1.is_finished())
   {
     Serial.print("t1.elapsed_time = ");
     debug(t1.elapsed_time);
   }
   else(t1.reset());  // continualy count to inifinity by reseting itself
   if(!t2.is_finished())
   {
     Serial.print("t2.elapsed_time = ");
     debug(t2.elapsed_time);
   }
   else(debug("Timer t2 has finished"));
 delay(200);
}
