/*
 * MyUltrasonic.cpp
 *
 * Library for MyUltrasonic Ranging Module in a minimalist way
 *
 * created 3 Apr 2014
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 23 Jan 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 04 Mar 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 15 May 2017
 * by Eliot Lim    (github: @eliotlim)
 * modified 10 Jun 2018
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 14 Jun 2018
 * by Otacilio Maia (github: @OtacilioN | linkedIn: in/otacilio)
 *
 * Released into the MIT License.
 */

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "MyUltrasonic.h"

MyUltrasonic::MyUltrasonic(uint8_t trigPin, uint8_t echoPin, unsigned long timeOut) {
  trig = trigPin;
  echo = echoPin;
  threePins = trig == echo ? true : false;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  timeout = timeOut;
  samples_sum = 0;
}

unsigned int MyUltrasonic::timing() {
  if (threePins)
    pinMode(trig, OUTPUT);

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  if (threePins)
    pinMode(trig, INPUT);

  previousMicros = micros();
  while(!digitalRead(echo) && (micros() - previousMicros) <= timeout); // wait for the echo pin HIGH or timeout
  previousMicros = micros();
  while(digitalRead(echo)  && (micros() - previousMicros) <= timeout); // wait for the echo pin LOW or timeout

  return micros() - previousMicros; // duration
}

/*
 * If the unit of measure is not passed as a parameter,
 * sby default, it will return the distance in centimeters.
 * To change the default, replace CM by INC.
 */
unsigned int MyUltrasonic::read(uint8_t und) {
  this-> distance = timing() / und / 2;  //distance by divisor;
  return this-> distance;
}

/*
 * This method is too verbal, so, it's deprecated.
 * Use read() instead.
 */
unsigned int MyUltrasonic::distanceRead(uint8_t und) {
  return read(und);
}

////////////////////////////////////////////////////// My modifications
int MyUltrasonic::get_average(int samples_count, int samples_interval) {
  samples[0] = read(CM) ;
  delay(samples_interval);

  // get the sum
  samples_sum += samples[0] - samples[samples_count];
  shift_samples(samples_count);
  // get the average
  samples_average = samples_sum / samples_count-1;
  if(samples_count == 1) samples_average = samples[0];
  return samples_average;  //distance by divisor
}
///////////////////------------------------------shift samples
void MyUltrasonic::shift_samples(int samples_count) {
  for(int i = samples_count; i > 0; i--)
  {
    samples[i] = samples[i-1];
  }
}
////////////////----------------------------------bool is_connected();
bool MyUltrasonic::is_connected() {
  return ( read(CM) > 0);
}
