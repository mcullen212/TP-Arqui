#include <timer.h>

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
