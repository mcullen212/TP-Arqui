/* sampleCodeModule.c */
#include <syscallFunctions.h>
#include <shell.h>
#include <libc.h>
#include <themes.h>
#include <references.h>

#define CHARACTER_COLOR 0xB0CA07
#define TAB_SIZE 4
#define HEADER_SIZE 6
#define MIN_X 8
#define MIN_Y 8
#define MAX_X 1008
#define MAX_Y 1008
#define WIDTH_FONT 8
#define HEIGHT_FONT 16
#define BUFFER_SIZE 256

int printShellHeader();
void exceptionHandler(uint64_t exceptionNumber, char * errorMessage);
void terminal();

static reference shellReference;

int main(void) {
    call_set_exception_handler(0, exceptionHandler);
    call_set_exception_handler(6, exceptionHandler);

    saveReference(&shellReference);

    terminal();

    return 0;
}

void terminal() {
    call_set_theme(themesShell[1]);

    char c;

    int cursorX = MIN_X, cursorY = MIN_Y, cursorScale = 1;
    call_c_init(cursorX, cursorY, cursorScale);

    while (1) {
        char  commandBuffer[BUFFER_SIZE] = {0};
        int yIndex, position;
        yIndex = printShellHeader();
        position = 0;

        while((c=getChar()) != '\n') {
            call_c_get_x(&cursorX); // X position of cursor
            call_c_get_y(&cursorY); // Y position of cursor
            call_c_get_scale(&cursorScale); // Scale of cursor
            if (c == 8) { // Backspace key
                if ( (cursorY != yIndex) || (cursorX > MIN_X + (HEADER_SIZE * WIDTH_FONT * cursorScale))) {
                    position--;
                    call_delete_char();
                }
            } else if (c == 9) { // Tab key
                for (int i = 0; i < TAB_SIZE; i++) {
                    commandBuffer[position++] = ' ';
                    call_draw_char(' ');
                }
            } else { // Any other key
                commandBuffer[position++] = c;
                call_draw_char(c);
            }
        } // When "enter" key is pressed, leaves typing loop.
        commandBuffer[position] = '\0';
        call_c_move(ENTER);
        shell(commandBuffer);
    }
}


// Prints shell header and returns the y index of the corresponding header.
int printShellHeader() {
    uint32_t n;
    call_write((uint8_t *) "user> ", &n);
    call_c_get_y((int *)&n);
    return n;
}

void exceptionHandler(uint64_t exceptionNumber, char * errorMessage) {
    call_set_theme(themesShell[6]);
    call_c_init(MIN_X, MIN_Y, 1);
    putString("\t\t\t\t\t\t\t\t\t\t\t\t");
    switch(exceptionNumber) {
        case 0 : // Division by Zero
            putString(errorMessage);
            break;
        case 6 : // Invalid Opcode
            putString(errorMessage);
            break;
        default :
            putString("ERROR - Unknown Exception");
            break;
    }

    call_get_registers();

    char c = 0;

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress \"ENTER\" key to continue..\n");

    do {
        c = getChar();
    } while(c == 0);

    jumpToReference(&shellReference);
}
