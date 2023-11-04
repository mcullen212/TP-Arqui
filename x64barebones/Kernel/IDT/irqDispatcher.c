#include <stdint.h>
#include <keyboardDriver.h>
#include <timer.h>

void int_00();
void int_01(uint64_t * registers);

void irqDispatcher(uint64_t irq, uint64_t * registers) {
    switch (irq) {
        case 0 : int_00(); break;
        case 1 : int_01(registers); break;
    }
}

// Interruption 00 ---------------------------
void int_00() {
    time_handler();
}
//--------------------------------------------

// Interruption 01 ---------------------------
void int_01(uint64_t * registers) {
    keyHandler(registers);
}
