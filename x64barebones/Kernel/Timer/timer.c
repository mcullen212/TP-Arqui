#include <timer.h>
#include <interruptions.h>

static unsigned long long ticks = 0;

void time_handler() {
	ticks++;
}

unsigned long long ticks_elapsed() {
	return ticks;
}

unsigned long long seconds_elapsed() {
	return (ticks / 18);
}

unsigned long long ms_elapsed() {
	return ticks * 55;
}
void sleep(unsigned long long ms) {
	unsigned long long intial_time = ms_elapsed();
	unsigned long long currentTime = intial_time;
    while( currentTime - intial_time <= ms) {
		currentTime = ms_elapsed();
	    _hlt();
    }
}
