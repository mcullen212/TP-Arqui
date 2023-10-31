#ifndef INTERRUPTIONS_H
#define INTERRUPTIONS_H

#include <stdint.h>

extern void _irq00Handler();
extern void _irq01Handler();
extern void _irq02Handler();
extern void _irq03Handler();
extern void _irq04Handler();
extern void _irq05Handler();
extern void _irq80Handler();

extern void _exception0Handler();
extern void _exception6Handler();

extern void _cli();
extern void _sti();
extern void hlt();

extern void picMasterMask(uint8_t mask);
extern void picSlaveMask(uint8_t mask);

extern void haltcpu();

#endif
