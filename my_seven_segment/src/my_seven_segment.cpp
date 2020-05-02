/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#include "my_seven_segment.h"

my_seven_segment::my_seven_segment(uint8_t ledA, uint8_t ledB, uint8_t ledC, uint8_t ledD, uint8_t ledE, uint8_t ledF, uint8_t ledG, uint8_t ledDP, String type)
{
  this->ledA = ledA;
  this->ledB = ledB;
  this->ledC = ledC;
  this->ledD = ledD;
  this->ledE = ledE;
  this->ledF = ledF;
  this->ledG = ledG;
  this->ledDP = ledDP;
  this->CC = (type=="CC");
}
my_seven_segment::my_seven_segment(uint8_t ledA, uint8_t ledB, uint8_t ledC, uint8_t ledD, uint8_t ledE, uint8_t ledF, uint8_t ledG, uint8_t ledDP)
{
  this->ledA = ledA;
  this->ledB = ledB;
  this->ledC = ledC;
  this->ledD = ledD;
  this->ledE = ledE;
  this->ledF = ledF;
  this->ledG = ledG;
  this->ledDP = ledDP;
  this->CC = HIGH;
}
//////////////////////////////////////////////-- begin
void my_seven_segment::begin()
{
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledDP, OUTPUT);
}
//////////////////////////////////////////////-- display digit
void my_seven_segment::display(uint8_t digit)
{
  switch (digit) {
    case 0:
      digitalWrite(ledA,!CC); digitalWrite(ledB,CC); digitalWrite(ledC,CC); digitalWrite(ledD,CC); digitalWrite(ledE,CC);digitalWrite(ledF,CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
      break;
    case 1:
      digitalWrite(ledA,!CC); digitalWrite(ledB,CC); digitalWrite(ledC,CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
      break;
    case 2:
      digitalWrite(ledA,CC); digitalWrite(ledB,CC); digitalWrite(ledC,!CC); digitalWrite(ledD,CC); digitalWrite(ledE,CC);digitalWrite(ledF,!CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
      break;
    case 3:
      digitalWrite(ledA,CC); digitalWrite(ledB,CC); digitalWrite(ledC,CC); digitalWrite(ledD,CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
      break;
    case 4:
      digitalWrite(ledA,!CC); digitalWrite(ledB,CC); digitalWrite(ledC,CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
      break;
    case 5:
      digitalWrite(ledA,CC); digitalWrite(ledB,!CC); digitalWrite(ledC,CC); digitalWrite(ledD,CC); digitalWrite(ledE,!CC);digitalWrite(ledF,CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
      break;
    case 6:
      digitalWrite(ledA,CC); digitalWrite(ledB,!CC); digitalWrite(ledC,CC); digitalWrite(ledD,CC); digitalWrite(ledE,CC);digitalWrite(ledF,CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
      break;
    case 7:
      digitalWrite(ledA,CC); digitalWrite(ledB,CC); digitalWrite(ledC,CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
      break;
    case 8:
      digitalWrite(ledA,CC); digitalWrite(ledB,CC); digitalWrite(ledC,CC); digitalWrite(ledD,CC); digitalWrite(ledE,CC);digitalWrite(ledF,CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
      break;
  }
}
//////////////////////////////////////////////-- display string
void my_seven_segment::display(String str)
{
    if(str== "ledA"){
      digitalWrite(ledA,CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "ledB"){
      digitalWrite(ledA,!CC); digitalWrite(ledB,CC); digitalWrite(ledC,!CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "ledC"){
      digitalWrite(ledA,!CC); digitalWrite(ledB,!CC); digitalWrite(ledC,CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "ledD"){
      digitalWrite(ledA,!CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "ledE"){
      digitalWrite(ledA,!CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,!CC); digitalWrite(ledE,CC);digitalWrite(ledF,!CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "ledF"){
      digitalWrite(ledA,!CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "ledG"){
      digitalWrite(ledA,!CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "ledDP"){
      digitalWrite(ledA,!CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,CC);
    }
    else if(str== "A"){
      digitalWrite(ledA,CC); digitalWrite(ledB,CC); digitalWrite(ledC,CC); digitalWrite(ledD,!CC); digitalWrite(ledE,CC);digitalWrite(ledF,CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "C"){
      digitalWrite(ledA,CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,CC); digitalWrite(ledE,CC);digitalWrite(ledF,CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "E"){
        digitalWrite(ledA,CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,CC); digitalWrite(ledE,CC);digitalWrite(ledF,CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
    }
      else if(str== "F"){
      digitalWrite(ledA,CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,!CC); digitalWrite(ledE,CC);digitalWrite(ledF,CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "U"){
        digitalWrite(ledA,!CC); digitalWrite(ledB,CC); digitalWrite(ledC,CC); digitalWrite(ledD,CC); digitalWrite(ledE,CC);digitalWrite(ledF,CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
    }
    else if(str== "H"){
        digitalWrite(ledA,!CC); digitalWrite(ledB,CC); digitalWrite(ledC,CC); digitalWrite(ledD,!CC); digitalWrite(ledE,CC);digitalWrite(ledF,CC); digitalWrite(ledG,CC); digitalWrite(ledDP,!CC);
    }

}
//////////////////////////////////////////////-- clear()
void my_seven_segment::clear()
{
  digitalWrite(ledA,!CC); digitalWrite(ledB,!CC); digitalWrite(ledC,!CC); digitalWrite(ledD,!CC); digitalWrite(ledE,!CC);digitalWrite(ledF,!CC); digitalWrite(ledG,!CC); digitalWrite(ledDP,!CC);
}
