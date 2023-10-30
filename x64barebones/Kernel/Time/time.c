#include <time.h>
#include <lib.h>
#include <videoDriver.h>

#define HEXA_BASE 16
#define LENGTH 8
#define HOURS 4
#define MINUTES 2
#define SECONDS 0

static void uintToBase(uint64_t value, uint8_t * buffer, uint32_t base)
{
	uint8_t *p = buffer;
	uint8_t *p1, *p2;
	int digit = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digit++;
	}
	while (value /= base);

	if(digit == 1){
		*p++ = '0';
		digit++;
	}

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

static void arg_time_zone(uint8_t *hours){
	int hour = 0;
	if(hours[0] == '0'){
		hour = hours[1] - '0';
	}else{
		hour = (hours[0] - '0')*10 + (hours[1] - '0');
	}

	if(hour<3){
		hour = 24 + hour - 3;
	}else{
		hour = hour - 3;
	}

	hours[0] = hour/10 + '0';
	hours[1] = hour%10 + '0';
}

uint8_t * get_time(){
	uint8_t * actualTime = {0};
    uint64_t hours = realTimeClock(HOURS), mins= realTimeClock(MINUTES), secs = realTimeClock(SECONDS);
    

    uintToBase(hours, actualTime, HEXA_BASE);
	arg_time_zone(actualTime);
	actualTime[2] = ':';
    uintToBase(mins, actualTime+3, HEXA_BASE);
	actualTime[5] = ':';
    uintToBase(secs, actualTime+6, HEXA_BASE);
	actualTime[8] = '\0';
	return actualTime;
}

