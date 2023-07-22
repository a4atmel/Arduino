

// ANALOG_BUFFER_2AI_2AQ IS CONNECTED TO CONTROLLER J5 SOCKET
/* -- 
 * DESIGNED BY ENG.AHMED MOHAMED ABD ELMAWGOUD
 * A4ATMEL88@GMAIL.COM
 * functions
 *  int read_ai0()          -- read from 0 to 100 [ 0v to 10v]
 *  int read_ai1()
 *  write_aq0(int value)    -- place from  0v to 10v [numbers from 0 to 100]
 *  write_aq1(int value)
 */

////////////////////////////////////////////// ONLY REPLACE J51 TO THE CONNECTED SOCKET
#define AI_0_pin  j51_pin3
#define AI_1_pin  j51_pin4
#define AQ_1_pin  j51_pin5
#define AQ_0_pin  j51_pin6

////////////////////////////////////////////// int map_analog(int adc_value)
int map_analog(int adc_value)
{
  int int_volt;
  if (adc_value < 140) int_volt =       ( adc_value * 10 ) / 140;  // int_volt <= 1 volt
  else if (adc_value < 425) int_volt =  ( adc_value * 20 ) / 425;  // int_volt <= 2 volt
  else if (adc_value < 720) int_volt =  ( adc_value * 30 ) / 720;  // int_volt <= 3 volt
  else if (adc_value < 990) int_volt =  ( adc_value * 40 ) / 990;  // int_volt <= 4 volt
  else if (adc_value < 1285) int_volt = ( adc_value * 50 ) / 1285; // int_volt <= 5 volt
  else if (adc_value < 1580) int_volt = ( adc_value * 60 ) / 1580; // int_volt <= 6 volt
  else if (adc_value < 1855) int_volt = ( adc_value * 70 ) / 1855; // int_volt <= 7 volt
  else if (adc_value < 2145) int_volt = ( adc_value * 80 ) / 2145; // int_volt <= 8 volt
  else if (adc_value < 2300) int_volt = ( adc_value * 85 ) / 2300; // int_volt <= 8.5 volt
  else if (adc_value > 2300) int_volt = 86; // int_volt 0= 8.5 volt
  return int_volt;
}
////////////////////////////////////////////////////////////////-- int read_ai1()
int read_ai0()  // return value from 0 to 100 as innput ranges from 0 to 10v
{
  int adc_value = analogRead(AI_0_pin);
  int voltage = map_analog(adc_value);
  return voltage;
}
////////////////////////////////////////////////////////////////-- int read_ai1()
int read_ai1()  // return value from 0 to 100 as innput ranges from 0 to 10v
{
  int adc_value = analogRead(AI_1_pin);
  int voltage = map_analog(adc_value);
  return voltage;
}
////////////////////////////////////////////////////////////////-- void write_ao1(int value)
void write_aq0(int value)  // value from 0 to 100 make output from 0 to 10 volts
{
  int dac_val = (value*512)/200;
  dacWrite(AQ_1_pin ,dac_val);
}
////////////////////////////////////////////////////////////////-- void write_ao1(int value)
void write_aq1(int value)  // value from 0 to 100 make output from 0 to 10 volts
{
  int dac_val = (value*512)/200;
  dacWrite(AQ_1_pin ,dac_val);
}

