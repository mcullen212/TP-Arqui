/* sampleCodeModule.c */
#include <syscallFunctions.h>
#include <shell.h>
#include <libc.h>
#include <themes.h>

#define CHARACTER_COLOR 0xB0CA07
#define TAB_SIZE 4
#define HEADER_SIZE 6
#define MIN_X 8
#define MIN_Y 8
#define MAX_X 1008
#define MAX_Y 1008
#define WIDTH_FONT 8
#define HEIGHT_FONT 16

int printShellHeader();

int main(void) {
    call_set_theme(themes[0]);

    char c;

    int cursorX = MIN_X, cursorY = MIN_Y, cursorScale = 3;
    call_c_init(cursorX, cursorY, cursorScale);

    while (1) {
        char * commandBuffer;
        int yIndex = printShellHeader();


        while((c=getChar()) != '\n') {
            call_c_get_x(&cursorX); // X position of cursor
            call_c_get_y(&cursorY); // Y position of cursor
            call_c_get_scale(&cursorScale); // Scale of cursor
            if (c == 8) { // Backspace key
                if ( (cursorY != yIndex) || (cursorX > MIN_X + (HEADER_SIZE * WIDTH_FONT * cursorScale))) {
                    commandBuffer--;
                    call_delete_char();
                }
            } else if (c == 9) { // Tab key
                for (int i = 0; i < TAB_SIZE; i++) {
                    *commandBuffer = ' ';
                    commandBuffer++;
                    call_draw_char(' ');
                }
            } else { // Any other key
                *commandBuffer = c;
                commandBuffer++;
                call_draw_char(c);
            }
        } // When "enter" key is pressed, leaves typing loop.
        *commandBuffer = '\0';
        int length;
        call_c_move(ENTER);
        //shell(commandBuffer);
    }
    return 0;
}


// Prints shell header and returns the y index of the corresponding header.
int printShellHeader() {
    uint32_t n;
    call_write((uint8_t *) "user> ", &n);
    call_c_get_y(&n);
    return n;
}

// int main() {
// 	//All the following code may be removed
// 	*v = 'X';
// 	*(v+1) = 0x74;

// 	//Test if BSS is properly set up
// 	if (var1 == 0 && var2 == 0)
// 		return 0xDEADC0DE;

// 	return 0xDEADBEEF;
// }
