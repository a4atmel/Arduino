/****************************************************/

#include "MyTimer.h"

MyTimer::MyTimer()
{
  bussy = false;
  start_time = 0;
  delay = 0;
}
//////////////////////////////////////////////-- start
bool MyTimer::start(int delay)
{
  this->delay = delay;
  elapsed_time = get_elapsed_time() ;
  if(!bussy && (delay >= elapsed_time ) ){
    start_time = millis();
    bussy = true;
  }
  if( elapsed_time >= delay){
    return true;
  }
  return false;
}
//////////////////////////////////////////////-- reset
void MyTimer::reset()
{
  bussy = false;
  //start_time = 0;
  start_time = millis();
}
//////////////////////////////////////////////-- is_finished
bool MyTimer::is_finished()
{
  return ( get_elapsed_time() >= delay );
}
//////////////////////////////////////////////-- get_elapsed_time
uint32_t MyTimer::get_elapsed_time()
{
  int elapsed_time = millis() - start_time;
  if( delay >= elapsed_time ) elapsed_time = millis() - start_time;
  else elapsed_time = delay;
  return elapsed_time;
}
