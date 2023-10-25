#include <syscalls.h>
#include <naiveConsole.h>
#include <keyboardDriver.h>
#include <videoDriver.h>

static int sys_read(unsigned int fd, char *buf, size_t count);
static void sys_write(unsigned int fd, const char *buf, size_t count);


void syscallsDispatcher(uint64_t rax, uint64_t * otherRegisters) {
    uint64_t rdi, rsi, rdx, rcx, r8; //r9;     // Me guardo los registros en variables para mayor claridad de lectura del codigo.
    rdi = otherRegisters[0];
    rsi = otherRegisters[1];
    rdx = otherRegisters[2];
    rcx = otherRegisters[3];
    r8 = otherRegisters[4];
    //r9 = otherRegisters[5];
    switch(rax) {
        case 0 : sys_read((unsigned int) rdi, (char *) rsi, (size_t) rdx); break;
        case 1 : sys_write((unsigned int) rdi, (char *) rsi, (size_t) rdx); break;
        case 2 : sys_draw_char((uint8_t) rdi, (uint32_t) rsi, (uint64_t) rdx, (uint64_t) rcx, (uint32_t) r8);
        case 3 : sys_delete_char((uint32_t) rdi, (uint64_t) rsi, (uint64_t) rdx, (uint32_t) rcx);
        default : break;
    }
}

// Syscall Read - ID = 0
static int sys_read(unsigned int fd, char *buf, size_t count) {
    return readFromKeyboard(buf,count);
}

// Syscall Write - ID = 1
static void sys_write(unsigned int fd, const char *buf, size_t count) {
    switch(fd) {
        case 1 : ncPrintWithColor(buf, WHITE, BLACK); break;
        case 2 : ncPrintWithColor(buf, RED, BLACK); break;
        default : break;
    }
}

// Syscall Draw char - ID = 2
static void sys_draw_char(uint8_t character, uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale){
    drawChar(character,hexColor,x,y,scale);
}

// Syscall Delete char - ID = 3
static void sys_delete_char(uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale) {
    deleteChar(hexColor,x,y,scale);
}
