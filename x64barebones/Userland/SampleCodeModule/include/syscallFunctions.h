#ifndef SYSCALL_FUNCTIONS_H
#define SYSCALL_FUNCTIONS_H

#include <stddef.h>
#include <stdint.h>

extern int call_read(unsigned int fd, char *buf, size_t count);
extern void call_write(unsigned int fd, const char *buf, size_t count);
extern void call_draw_char(uint8_t character, uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);
extern void call_delete_char(uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);
extern char * call_get_time();

#endif
