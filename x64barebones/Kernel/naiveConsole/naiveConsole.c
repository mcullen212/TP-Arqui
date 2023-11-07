#include <naiveConsole.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static uint8_t * const video = (uint8_t*)0xB8000;
static uint8_t * currentVideo = (uint8_t*)0xB8000;
static const uint32_t width = 80;
static const uint32_t height = 25 ;

extern int getRTCHour();
extern uint64_t poolKey();

static uint8_t makeColor(VGAColor lineColor, VGAColor fillColor) {
    return (uint8_t)(lineColor | fillColor << 4);
}

void ncPrintCharWithColor(char character, VGAColor lineColor, VGAColor fixColor) {
    uint8_t * location = currentVideo; //Asigno el puntero a la locacion donde se quiere "imprimir"

    *location = character;      //Seteo el caracter
    location++;                 // Avanzo a la posicion del color
    *location = makeColor(lineColor,fixColor);  //Seteo el color

    currentVideo += 2;  //Avanzo puntero en la pantalla
}

void ncPrintWithColor(const char * string, VGAColor lineColor, VGAColor fixColor) {
    for (int i = 0; string[i] != '\0'; i++) {
        ncPrintCharWithColor(string[i],lineColor,fixColor);
    }
}

void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncPrintChar(char character)
{
	*currentVideo = character;
	currentVideo += 2;
}

void ncNewline()
{
	do
	{
		ncPrintChar(' ');
	}
	while((uint64_t)(currentVideo - video) % (width * 2) != 0);
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear()
{
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideo = video;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}

void ncGetRTCHour() {
    // ncPrint("Real Time Clock Hour: ");
    // uint64_t hour = getRTCHour();
    // ncPrintHex(hour);
}

void ncPoolChar() {
    // ncPrint("Press any key: ");

    // uint8_t character = getKeyMapping(poolKey());
    // ncPrintChar(character);
}
