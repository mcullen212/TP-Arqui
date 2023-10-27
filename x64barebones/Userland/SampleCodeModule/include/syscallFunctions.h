#ifndef SYSCALL_FUNCTIONS_H
#define SYSCALL_FUNCTIONS_H

#include <stddef.h>
#include <stdint.h>

int call_read(unsigned int fd, char *buf, size_t count);
void call_write(unsigned int fd, const char *buf, size_t count);
void call_draw_char(uint64_t character, uint64_t hexColor, uint64_t x, uint64_t y, uint64_t scale);
void call_delete_char(uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);

#endif
