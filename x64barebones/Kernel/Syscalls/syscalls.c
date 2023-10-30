#include <syscalls.h>
#include <naiveConsole.h>
#include <keyboardDriver.h>
#include <videoDriver.h>

static void sys_read(uint8_t * buf, uint32_t count, uint32_t * readBytes);
static void sys_write(uint8_t * buf, uint32_t x, uint32_t y, uint32_t scale, uint32_t * count);
static void sys_draw_char(uint8_t character, uint32_t x, uint32_t y, uint32_t scale);
static void sys_delete_char( uint32_t x, uint32_t y, uint32_t scale) ;
static void sys_shell_theme(uint32_t textColor, uint32_t backColor);


void syscallsDispatcher(uint64_t rax, uint64_t *otherRegisters) {
    uint64_t rdi,rsi,rdx,rcx,r8; //r9;     // Me guardo los registros en variables para mayor claridad de lectura del codigo.
    rdi = otherRegisters[0];
    rsi = otherRegisters[1];
    rdx = otherRegisters[2];
    rcx = otherRegisters[3];
    r8 = otherRegisters[4];
    //r9 = otherRegisters[5];
    switch(rax) {
        case 0 : 
            sys_read((uint8_t *) rdi, (uint32_t) rsi, (uint32_t *) rdx); 
            break;
        case 1 : 
            sys_write((uint8_t *) rdi, (uint8_t) rsi, (uint32_t) rdx, (uint32_t) rcx, (uint32_t *) r8); 
            break;
        case 2 : 
            sys_draw_char((uint8_t) rdi, (uint32_t) rsi, (uint32_t) rdx, (uint32_t) rcx); 
            break;
        case 3 : 
            sys_delete_char((uint32_t) rdi, (uint32_t) rsi, (uint32_t) rdx); 
            break;
        // case 4 : 
        //     //sys_time();
        //     break;
        case 5 :
            sys_shell_theme((uint32_t) rdi, (uint32_t) rsi);
            break;
        default : 
            break;
    }
}

// Syscall Read - ID = 0
void sys_read(uint8_t * buf, uint32_t count, uint32_t * readBytes) {
    readFromKeyboard(buf, count, readBytes);
}

// Syscall Write - ID = 1
void sys_write(uint8_t * buf, uint32_t x, uint32_t y, uint32_t scale, uint32_t * count) {
    drawString(buf, x, y, scale, count);
}

// Syscall Draw char - ID = 2
void sys_draw_char(uint8_t character, uint32_t x, uint32_t y, uint32_t scale){
    drawChar(character,  x, y, scale);
}

// Syscall Delete char - ID = 3
void sys_delete_char(uint32_t x, uint32_t y, uint32_t scale) {
    deleteChar( x, y, scale);
}

// Syscall theme  - ID = 5
void sys_shell_theme(uint32_t textColor, uint32_t backColor) {
    setColor(textColor, backColor);
}