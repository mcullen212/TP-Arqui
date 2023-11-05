#ifndef REFERENCES_H
#define REFERENCES_H

#include <stdint.h>

typedef struct { // Registers that are not intended parameter passing.
    uint64_t r15;
    uint64_t r14;
    uint64_t r13;
    uint64_t r12;
    uint64_t r11;
    uint64_t rcx;
    uint64_t rbx;
    uint64_t rflags;
    uint64_t rsp;
    uint64_t rip;
} reference;

void saveReference(reference * reference);

void jumpToReference(reference * reference);

#endif
