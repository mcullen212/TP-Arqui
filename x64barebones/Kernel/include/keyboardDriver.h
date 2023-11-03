#ifndef KEYBOARD_DRIVER_H
#define KEYBOARD_DRIVER_H

#include <stdint.h>

#define LEFT_SHIFT_PRESSED 42
#define RIGHT_SHIFT_PRESSED 54
#define CAPS_LOCK_PRESSED 58
#define LEFT_ALT_PRESSED 56
#define LEFT_ALT_RELEASED 184
#define RELEASED 128
#define LEFT_SHIFT_RELEASED 170
#define RIGHT_SHIFT_RELEASED 182
#define BUFFER_SIZE 256
#define REGISTERS_AMOUNT 20

void keyHandler();
void readFromKeyboard(uint8_t * toRetbuffer, uint32_t amount, uint32_t * size);
int getKeyNumber();
void valueToHexString(unsigned long long value, uint8_t * hexStr);
int intToBase(uint64_t num, int base, char*buffer);
char savedRegs();

static char * registersName[REGISTERS_AMOUNT] = {"R15 = ", "R14 = ", "R13 = ", "R12 = ", "R11 = ", "R10 = ", "R9 = ", "R8 = ", "RSI = ", "RDI = ", "RBP = ", "RDX = ", "RCX = ", "RBX = ", "RAX = ", "RIP  = ", "CS = ", "RFLAGS = ", "RSP = ", "SS = "};
static uint64_t currentRegisters[REGISTERS_AMOUNT];


#endif
