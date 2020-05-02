
#ifndef _my_seven_segment_h
#define _my_seven_segment_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class my_seven_segment
{
private:
	uint8_t ledA, ledB, ledC, ledD, ledE, ledF, ledG, ledDP;
	bool CC; // if it common cathode
public:
	my_seven_segment::my_seven_segment(uint8_t ledA, uint8_t ledB, uint8_t ledC, uint8_t ledD, uint8_t ledE, uint8_t ledF, uint8_t ledG, uint8_t ledDP, String type);
	my_seven_segment::my_seven_segment(uint8_t ledA, uint8_t ledB, uint8_t ledC, uint8_t ledD, uint8_t ledE, uint8_t ledF, uint8_t ledG, uint8_t ledDP);
	void begin();
	void display(uint8_t digit);
	void display(String str);
	void clear();
};

#endif
