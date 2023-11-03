#include <stdint.h>
#include <keyboardDriver.h>

void int_00();
void int_01(uint64_t * registers);

void irqDispatcher(uint64_t irq, uint64_t * registers) {
    switch (irq) {
        case 0 : int_00(); break;
        case 1 : int_01(registers); break;
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
void int_01(uint64_t * registers) {
    keyHandler(registers);
}
