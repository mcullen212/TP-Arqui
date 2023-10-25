#ifndef KEYBOARD_DRIVER_H
#define KEYBOARD_DRIVER_H

#include <stdint.h>

#define LEFT_SHIFT_PRESSED 42
#define RIGHT_SHIFT_PRESSED 54
#define CAPS_LOCK_PRESSED 58
#define RELEASED 128
#define LEFT_SHIFT_RELEASED 170
#define RIGHT_SHIFT_RELEASED 182
#define BUFFER_SIZE 256

void keyHandler();
int readFromKeyboard(char * toRetbuffer, int amount);
int getKeyNumber();

#endif
