/* sampleCodeModule.c */
#include <syscallFunctions.h>
#include <shellMovement.h>
#include <libc.h>
#include <themes.h>
#include <commands.h>

#define CHARACTER_COLOR 0xB0CA07
#define TAB_SIZE 4
#define HEADER_SIZE 6

static Cursor cursor;

int main(void) {
    call_set_theme(themes[5]);
    inicializeCursor(&cursor, MIN_X, MIN_Y, 1);

    char c;

    while (1) {
        char * commandBuffer;
        int yIndex = printShellHeader();
        moveCursor(&cursor, ENTER);
        time(&cursor);
        while((c=getChar()) != '\n') {
            if (c == 8) { // Backspace key
                if ( (cursor.y != yIndex) || (cursor.x > MIN_X + (HEADER_SIZE * WIDTH_FONT * cursor.scale))) {
                    commandBuffer--;
                    moveCursor(&cursor, DELETE);
                    call_delete_char(cursor.x, cursor.y, cursor.scale);
                }
            } else if (c == 9) { // Tab key
                for (int i = 0; i < TAB_SIZE; i++) {
                    *commandBuffer = ' ';
                    commandBuffer++;
                    call_draw_char(' ', cursor.x, cursor.y, cursor.scale);
                    moveCursor(&cursor, WRITE);
                }
            } else { // Any other key
                *commandBuffer = c;
                commandBuffer++;
                call_draw_char(c, cursor.x, cursor.y, cursor.scale);
                moveCursor(&cursor, WRITE);
            }
        } // When "enter" key is pressed, leaves typing loop.
        *commandBuffer = '\0';
        moveCursor(&cursor, ENTER);
    }
    return 0;
}


// Prints shell header and returns the y index of the corresponding header.
int printShellHeader() {
    int length;
    call_write("user> ", cursor.x, cursor.y, cursor.scale, &length);
    while (length > 0) {
        moveCursor(&cursor, WRITE);
        length--;
    }
    return cursor.y;
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
