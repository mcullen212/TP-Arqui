#include <syscalls.h>
#include <keyboardDriver.h>
#include <videoDriver.h>
#include <time.h>
#include <exceptions.h>


static void sys_read(uint8_t * buf, uint32_t count, uint32_t * readBytes);
static void sys_write(uint8_t * buf, uint32_t x, uint32_t y, uint32_t scale, uint32_t * count);
static void sys_draw_char(uint8_t character, uint32_t x, uint32_t y, uint32_t scale);
static void sys_delete_char( uint32_t x, uint32_t y, uint32_t scale) ;
static void sys_shell_theme(uint32_t * theme);
static void sys_time(uint8_t ** currentTime);
static void sys_set_exception_handler(uint64_t number, exceptionHandler exception);


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
        case 4 :
            sys_time((uint8_t **) rdi);
            break;
        case 5 :
            sys_shell_theme((uint32_t *) rdi);
            break;
        case 6 :
            sys_set_exception_handler((uint64_t) rdi, (exceptionHandler) rsi);
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

//Syscall Time - ID = 4
void sys_time(uint8_t ** currentTime){
    *currentTime = get_time();
}

// Syscall theme  - ID = 5
void sys_shell_theme(uint32_t * theme) {
    uint32_t font_color = theme[1], background_color = theme[0];
    setColor(font_color, background_color);
}

static void sys_set_exception_handler(uint64_t number, exceptionHandler exception) {
    setExceptionHandler(number, exception);
}
