#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <idtManager.h>
#include <videoDriver.h>

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

static void * const sampleCodeModuleAddress = (void*)0x400000;
static void * const sampleDataModuleAddress = (void*)0x500000;

typedef int (*EntryPoint)();


void clearBSS(void * bssAddress, uint64_t bssSize)
{
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary()
{
	char buffer[10];

	ncPrint("[x64BareBones]");
	ncNewline();

	ncPrint("CPU Vendor:");
	ncPrint(cpuVendor(buffer));
	ncNewline();

	ncPrint("[Loading modules]");
	ncNewline();
	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);
	ncPrint("[Done]");
	ncNewline();
	ncNewline();

	ncPrint("[Initializing kernel's binary]");
	ncNewline();

	clearBSS(&bss, &endOfKernel - &bss);

	ncPrint("  text: 0x");
	ncPrintHex((uint64_t)&text);
	ncNewline();
	ncPrint("  rodata: 0x");
	ncPrintHex((uint64_t)&rodata);
	ncNewline();
	ncPrint("  data: 0x");
	ncPrintHex((uint64_t)&data);
	ncNewline();
	ncPrint("  bss: 0x");
	ncPrintHex((uint64_t)&bss);
	ncNewline();

	ncPrint("[Done]");
	ncNewline();
	ncNewline();
	return getStackBase();
}

int main()
{
	//Descomentar las lineas de abajo y el ncPoolChar de navieConsole.c

    loadIDT();

	((EntryPoint)sampleCodeModuleAddress)();
	
	//drawChar('R', COLOR_RED, 70,100, 7);
	// drawChar('I', COLOR_WHITE, 70+9*7,100, 7);
	// drawChar('V', COLOR_RED, 70+2*9*7,100, 7);
	// drawChar('E', COLOR_WHITE, 70+3*9*7,100, 7);
	// drawChar('R', COLOR_RED, 70+4*9*7,100, 7);
	// deleteChar(0xFF0000, 200,500, 4);
	// drawChar(' ', 0xFF0000, 100+9*7,299, 7);
	// drawChar('B', COLOR_BLUE, 100+2*9*7, 299,7);
	// drawChar('O', COLOR_YELLOW, 100+3*9*7, 299,7);
	// drawChar('C', COLOR_BLUE, 100+4*9*7, 299,7);
	// drawChar('A', COLOR_YELLOW, 100+5*9*7, 299,7);
	// drawChar('a', 0xFF0000, 100 + 19, 50 + 10,2);
	// drawChar('*', 0xFF0000, 0,0, 3);

    while(1);
	return 0;
}
