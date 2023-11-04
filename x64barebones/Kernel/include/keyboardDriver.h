#ifndef KEYBOARD_DRIVER_H
#define KEYBOARD_DRIVER_H

#include <stdint.h>

#define LEFT_SHIFT_PRESSED 42
#define RIGHT_SHIFT_PRESSED 54
#define CAPS_LOCK_PRESSED 58
#define LEFT_ALT_PRESSED 56
#define ESC_PRESSED 1
#define CTRL_PRESSED 29

#define RELEASED 59
#define LEFT_ALT_RELEASED 184
#define LEFT_SHIFT_RELEASED 170
#define RIGHT_SHIFT_RELEASED 182

#define BUFFER_SIZE 256
#define REGISTERS_AMOUNT 20

void keyHandler();
void readFromKeyboard(uint8_t * toRetbuffer, uint32_t amount, uint32_t * size);
int getKeyNumber();
void valueToHexString(unsigned long long value, uint8_t * hexStr);
void copyRegisters(uint64_t num, char*buffer);
char savedRegs();
uint8_t * getRegisterName(int index);
uint64_t getRegisterValue(int index);
uint32_t getBackgroundColor();
void updateRegs(uint64_t * registers);

#endif
