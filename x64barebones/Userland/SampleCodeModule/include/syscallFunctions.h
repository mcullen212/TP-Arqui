#ifndef SYSCALL_FUNCTIONS_H
#define SYSCALL_FUNCTIONS_H

#include <stddef.h>
#include <stdint.h>

void call_read(unsigned int fd, char *buf, size_t count, uint32_t * size);
void call_write(unsigned int fd, const char *buf, size_t count);
void call_draw_char(uint8_t character, uint32_t hexColor, uint32_t x, uint32_t y, uint32_t scale);
void call_delete_char(uint32_t hexColor, uint32_t x, uint32_t y, uint32_t scale);
#endif
