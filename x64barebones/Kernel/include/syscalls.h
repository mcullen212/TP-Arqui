#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>
#include <stddef.h>

void syscallsDispatcher(uint64_t rax, uint64_t * otherRegisters);

#endif
