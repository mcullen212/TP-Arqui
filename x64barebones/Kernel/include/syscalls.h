#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>
#include <stddef.h>

void syscallsDispatcher(uint64_t rax, uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t * r9);

#endif
