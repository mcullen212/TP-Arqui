#include <syscalls.h>
#include <naiveConsole.h>

static void sys_read(unsigned int fd, char *buf, size_t count);
static void sys_write(unsigned int fd, const char *buf, size_t count);


void syscallsDispatcher(uint64_t rax, uint64_t * otherRegisters) {
    uint64_t rdi, rsi, rdx;//rcx, r8, r9;     // Me guardo los registros en variables para mayor claridad de lectura del codigo.
    rdi = otherRegisters[0];
    rsi = otherRegisters[1];
    rdx = otherRegisters[2];
    //rcx = otherRegisters[3];
    //r8 = otherRegisters[4];
    //r9 = otherRegisters[5];
    ncPrintDec(rax);
    switch(rax) {
        case 0 : sys_read((unsigned int) rdi, (char *) rsi, (size_t) rdx); break;
        case 1 : sys_write((unsigned int) rdi, (char *) rsi, (size_t) rdx); break;
        default : break;
    }
}

// Syscall Write - ID = 0
static void sys_read(unsigned int fd, char *buf, size_t count) {

}

// Syscall Write - ID = 1
static void sys_write(unsigned int fd, const char *buf, size_t count) {
    switch(fd) {
        case 1 : ncPrintWithColor(buf, WHITE, BLACK); break;
        case 2 : ncPrintWithColor(buf, RED, BLACK); break;
        default : break;
    }
}
