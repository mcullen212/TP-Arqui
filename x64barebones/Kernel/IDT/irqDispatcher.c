#include <stdint.h>
#include <naiveConsole.h>

void int_00();
void int_01();

void irqDispatcher(uint64_t irq) {
    switch (irq) {
        case 0 : int_00(); break;
        case 1 : int_01(); break;
    }
}

// Interruption 00 ---------------------------
static unsigned long ticks = 0;

void time_handler() {
    ticks++;
}

void int_00() {
    time_handler();
    if ((ticks % (5000 / 55)) == 0) {
        //ncPrint("Algo ");
    }
}
//--------------------------------------------

// Interruption 01 ---------------------------
void int_01() {
    keyHandler();
}
