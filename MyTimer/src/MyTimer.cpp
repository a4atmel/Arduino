/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#include "MyTimer.h"

MyTimer::MyTimer()
{
  bussy = false;
  start_time = 0;
  delay = 0;
}
//////////////////////////////////////////////-- start
void MyTimer::start(int delay)
{
  this->delay = delay;
  elapsed_time = millis() - start_time ;
  if(!bussy){
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
  start_time = 0;
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
  return elapsed_time;
}
