#include <syscalls.h>
#include <keyboardDriver.h>
#include <videoDriver.h>
#include <time.h>
#include <exceptions.h>
#include <cursor.h>
#include <timer.h>
#include <interruptions.h>

typedef enum {SYS_READ = 0, SYS_WRITE, DRAW_C, DELETE_C, TIME, THEME, SET_EXC, C_GET_X, C_GET_Y, C_GET_S, C_SET_S, C_MOVE, C_INIT, SET_COLORS, GET_REGS, DRAW_SQUARE, COLOR_SCREEN, DRAW_CIRCLE, CLEAR_SCREEN, SLEEP, GET_TICKS}SysID;


static void sys_read(uint8_t * buf, uint32_t count, uint32_t * readBytes);
//static void sys_write(uint8_t * buf, uint32_t x, uint32_t y, uint32_t scale, uint32_t * count);
static void sys_write(uint8_t * buf, uint32_t * count);
//static void sys_draw_char(uint8_t character, uint32_t x, uint32_t y, uint32_t scale);
static void sys_draw_char(uint8_t character);
//static void sys_delete_char( uint32_t x, uint32_t y, uint32_t scale) ;
static void sys_delete_char();
static void sys_shell_theme(uint32_t * theme);
static void sys_time(uint8_t ** currentTime);
static void sys_set_exception_handler(uint64_t number, exceptionHandler exception);
static void sys_get_cursor_x(int * x);
static void sys_get_cursor_y(int * y);
static void sys_get_cursor_scale(int * scale);
static void sys_set_cursor_scale(int scale);
static void sys_move_cursor(actionOfCursor action);
static void sys_init_cursor(int x, int y, int scale);
static void sys_set_colors(uint32_t textColor, uint32_t backgroundColor);
static void sys_get_registers();
static void sys_draw_square(uint32_t hexColor,uint64_t x, uint64_t y, uint32_t scale);
static void sys_color_screen(uint32_t hexColor);
static void sys_draw_circle(uint32_t color, uint32_t x, uint32_t y, uint32_t length);
static void sys_clear_screen();
static void sys_sleep(unsigned long long ms);
static void sys_get_ticks(unsigned long long * ticks);


void syscallsDispatcher(uint64_t rax, uint64_t *otherRegisters) {
    uint64_t rdi,rsi,rdx,rcx;// r8, r9;     // Me guardo los registros en variables para mayor claridad de lectura del codigo.
    rdi = otherRegisters[0];
    rsi = otherRegisters[1];
    rdx = otherRegisters[2];
    rcx = otherRegisters[3];
    //r8 = otherRegisters[4];
    //r9 = otherRegisters[5];
    switch(rax) {
        case SYS_READ :
            sys_read((uint8_t *) rdi, (uint32_t) rsi, (uint32_t *) rdx);
            break;
        case SYS_WRITE :
            sys_write((uint8_t *) rdi, (uint32_t *) rsi);
            break;
        case DRAW_C :
            sys_draw_char((uint8_t) rdi);
            break;
        case DELETE_C :
            sys_delete_char();
            break;
        case TIME :
            sys_time((uint8_t **) rdi);
            break;
        case THEME :
            sys_shell_theme((uint32_t *) rdi);
            break;
        case SET_EXC :
            sys_set_exception_handler((uint64_t) rdi, (exceptionHandler) rsi);
            break;
        case C_GET_X :
            sys_get_cursor_x((int *) rdi);
            break;
        case C_GET_Y :
            sys_get_cursor_y((int *) rdi);
            break;
        case C_GET_S :
            sys_get_cursor_scale((int *) rdi);
            break;
        case C_SET_S :
            sys_set_cursor_scale((int) rdi);
            break;
        case C_MOVE :
            sys_move_cursor((actionOfCursor) rdi);
            break;
        case C_INIT :
            sys_init_cursor((int) rdi, (int) rsi, (int) rdx);
            break;
        case SET_COLORS :
            sys_set_colors((uint32_t) rdi, (uint32_t) rsi);
            break;
        case GET_REGS :
            sys_get_registers();
            break;
        case DRAW_SQUARE:
            sys_draw_square((uint32_t) rdi, (uint32_t) rsi, (uint32_t) rdx, (uint32_t) rcx);
            break;
        case COLOR_SCREEN :
            sys_color_screen((uint32_t) rdi);
            break;
        case DRAW_CIRCLE :
            sys_draw_circle((uint32_t) rdi, (uint32_t) rsi, (uint32_t) rdx, (uint32_t) rcx);
        case CLEAR_SCREEN :
            sys_clear_screen();
            break;
        case SLEEP :
            sys_sleep((unsigned long long) rdi);
            break;
        case GET_TICKS :
            sys_get_ticks((unsigned long long *) rdi);
            break;
        default :
            break;
    }
}

// Syscall Read - ID = 0
static void sys_read(uint8_t * buf, uint32_t count, uint32_t * readBytes) {
    readFromKeyboard(buf, count, readBytes);
}

// Syscall Write - ID = 1
static void sys_write(uint8_t * buf, uint32_t * count) {
    drawStringOnCursor(buf, count);
}

// Syscall Draw char - ID = 2
static void sys_draw_char(uint8_t character){
    drawCharOnCursor(character);
}

// Syscall Delete char - ID = 3
static void sys_delete_char() {
    deleteCharOnCursor();
}

//Syscall Time - ID = 4
static void sys_time(uint8_t ** currentTime){
    *currentTime = get_time();
}

// Syscall theme  - ID = 5
static void sys_shell_theme(uint32_t * theme) {
    uint32_t font_color = theme[1], background_color = theme[0];
    setColor(font_color, background_color);
    sys_color_screen(background_color);
}

static void sys_set_exception_handler(uint64_t number, exceptionHandler exception) {
    setExceptionHandler(number, exception);
}

static void sys_get_cursor_x(int * x) {
    *x = getCursorX();
}


static void sys_get_cursor_y(int * y) {
    *y = getCursorY();
}

static void sys_get_cursor_scale(int * scale) {
    *scale = getCursorScale();
}

static void sys_set_cursor_scale(int scale) {
    setCursorScale(scale);
}

static void sys_move_cursor(actionOfCursor action) {
    moveCursor(action);
}

static void sys_init_cursor(int x, int y, int scale) {
    initializeCursor(x, y, scale);
}

static void sys_set_colors(uint32_t textColor, uint32_t backgroundColor) {
    setColor(textColor,backgroundColor);
}

static void sys_get_registers(){
    if(!savedRegs()){
        uint32_t length;
        sys_write((uint8_t *)"Registers must be saved.\n", &length);
        return;
    }
    uint32_t length;
    char toHex[18];
    for(int i = REGISTERS_AMOUNT-1; i >= 0; i--) {
        copyRegisters(getRegisterValue(i), toHex);
        sys_write(getRegisterName(i), &length);
        sys_write((uint8_t *) toHex, &length);
        sys_write((uint8_t *)"\n", &length);
    }
}

static void sys_draw_square(uint32_t hexColor,uint64_t x, uint64_t y, uint32_t scale){
    drawSquare(hexColor,x,y,scale);
}

static void sys_color_screen(uint32_t hexColor) {
    colorScreen(hexColor);
}

static void sys_draw_circle(uint32_t color, uint32_t x, uint32_t y, uint32_t length) {
    drawCircle(color, x, y, length);
}

static void sys_clear_screen() {
    colorScreen(getBackgroundColor());
    int scale;
    sys_get_cursor_scale(&scale);
    sys_init_cursor(MIN_X, MIN_Y, scale);
}

static void sys_sleep(unsigned long long ms) {
    unsigned long long intial_time = ms_elapsed();
    while( (ms_elapsed() - intial_time) <= ms ) {
        _hlt();
    }
}

static void sys_get_ticks(unsigned long long * ticks) {
    *ticks = ticks_elapsed();
}
