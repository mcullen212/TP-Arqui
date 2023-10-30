/* sampleCodeModule.c */
#include <syscallFunctions.h>
#include <shellMovement.h>
#include <libc.h>
#include <themes.h>

#define CHARACTER_COLOR 0xB0CA07
#define TAB_SIZE 4
#define HEADER_SIZE 6

int printShellHeader();

static Cursor cursor;

int main(void) {
    call_set_theme(COLOR_WHITE, COLOR_BLACK);
    inicializeCursor(&cursor, MIN_X, MIN_Y, 3);

    char c;

    while (1) {
        char * commandBuffer;
        int yIndex = printShellHeader();
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
    uint32_t length;
    call_write((uint8_t *) "user> ", cursor.x, cursor.y, cursor.scale, &length);
    while (length > 0) {
        moveCursor(&cursor, WRITE);
        length--;
    }
    return cursor.y;
}

Cursor getCursor() {
    return cursor;
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
