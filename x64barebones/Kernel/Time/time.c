#include <time.h>
#include <stdint.h>
#include <lib.h>
#include <videoDriver.h>

#define HEXA_BASE 16
#define LENGTH 8
#define HOURS 4
#define MINUTES 2
#define SECONDS 0

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

    char actualTime[LENGTH];
    

    uint64_t hours = realTimeClock(HOURS), mins= realTimeClock(MINUTES), secs = realTimeClock(SECONDS);
    

    uintToBase(hours, actualTime, HEXA_BASE);
	actualTime[2] = ':';
    uintToBase(mins, actualTime+3, HEXA_BASE);
	actualTime[5] = ':';
    uintToBase(secs, actualTime+6, HEXA_BASE);
    
    return actualTime;

}

