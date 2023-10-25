#ifndef SYSCALL_FUNCTIONS_H
#define SYSCALL_FUNCTIONS_H

call_read(unsigned int fd, char *buf, size_t count);
call_write(unsigned int fd, const char *buf, size_t count);
call_draw_char(uint8_t character, uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);
call_delete_char(uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);

#endif
