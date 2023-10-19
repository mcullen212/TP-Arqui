#ifndef KEYBOARD_DRIVER_H
#define KEYBOARD_DRIVER_H

#include <stdint.h>

uint8_t getKeyMapping(uint64_t number);
uint8_t getKeyPressed();
extern uint8_t getKeyNumber();

#endif
