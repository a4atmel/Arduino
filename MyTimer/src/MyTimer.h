
#ifndef _MyTimer_h
#define _MyTimer_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MyTimer
{
private:
	uint32_t start_time = 0;
public:
	bool bussy = false ;
	uint32_t elapsed_time = 0;
	uint32_t delay = 0;
	MyTimer();
	void start(int delay);
	void reset();
	bool is_finished();
	uint32_t get_elapsed_time();
};

#endif
