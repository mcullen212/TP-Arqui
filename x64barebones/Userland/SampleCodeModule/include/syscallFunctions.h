#ifndef SYSCALL_FUNCTIONS_H
#define SYSCALL_FUNCTIONS_H

#include <stddef.h>
#include <stdint.h>

int call_read(char *buf, size_t count);
void call_write(const char *buf, size_t count);
void call_draw_char(uint8_t character, uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);
void call_delete_char(uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);

#endif
