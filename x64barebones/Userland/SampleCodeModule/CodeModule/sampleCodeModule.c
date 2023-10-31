/* sampleCodeModule.c */
#include <syscallFunctions.h>
#include <cursor.h>
#include <shell.h>
#include <libc.h>
#include <themes.h>

#define CHARACTER_COLOR 0xB0CA07
#define TAB_SIZE 4
#define HEADER_SIZE 6

int printShellHeader();

int main(void) {
    call_set_theme(themes[0]);

    char c;

    while (1) {
        char * commandBuffer;
        int yIndex = printShellHeader();
        cursorAction(ENTER);
        printf("funciona el printf %d\n",1);

        
        //time(getCursor());
        
        while((c=getChar()) != '\n') {
            if (c == 8) { // Backspace key
                if ( (getCursorY() != yIndex) || (getCursorX() > MIN_X + (HEADER_SIZE * WIDTH_FONT * getCursorScale()))) {
                    commandBuffer--;
                    cursorAction(DELETE);
                    call_delete_char(getCursorX(), getCursorY(), getCursorScale());
                }
            } else if (c == 9) { // Tab key
                for (int i = 0; i < TAB_SIZE; i++) {
                    *commandBuffer = ' ';
                    commandBuffer++;
                    call_draw_char(' ', getCursorX(), getCursorY(), getCursorScale());
                    cursorAction(WRITE);
                }
            } else { // Any other key
                *commandBuffer = c;
                commandBuffer++;
                call_draw_char(c, getCursorX(), getCursorY(), getCursorScale());
                cursorAction(WRITE);
            }
        } // When "enter" key is pressed, leaves typing loop.
        *commandBuffer = '\0';
        cursorAction(ENTER);
        //shell(commandBuffer);
    }
    return 0;
}


// Prints shell header and returns the y index of the corresponding header.
int printShellHeader() {
    uint32_t length;
    call_write((uint8_t *) "user> ", getCursorX(), getCursorY(), getCursorScale(), &length);
    moveCursor(length, 0);
    return getCursorY();
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
