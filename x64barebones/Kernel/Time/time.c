#include <time.h>
#include <stdint.h>
#include <lib.h>

#define HEXA_BASE 16

static void uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p -1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

}

char * get_time(){

    char actualTime[8] = {0};
    

    uint64_t hours = realTimeClock(4), mins= realTimeClock(2), secs = realTimeClock(0);
    

    uintToBase(hours, actualTime, HEXA_BASE);
    uintToBase(mins, actualTime+3, HEXA_BASE);
    uintToBase(secs, actualTime+6, HEXA_BASE);

    actualTime[3] = ':';
    actualTime[5] = ':';
    
    return actualTime;

}

