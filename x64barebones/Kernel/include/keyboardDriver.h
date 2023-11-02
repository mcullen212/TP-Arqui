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
#define REGISTERS_AMOUNT 19

void keyHandler();
void readFromKeyboard(uint8_t * toRetbuffer, uint32_t amount, uint32_t * size); 
int getKeyNumber();
void valueToHexString(uint64_t value, char *hexStr);

typedef struct {
    uint64_t rbp, rsp, rip, rax, rbx, rcx, rdx, rdi, rsi, r8, r9, r10, r11, r12, r13, r14, r15, cs, rflags, ss;
}registersCopy;

static registersCopy regs;

#endif
