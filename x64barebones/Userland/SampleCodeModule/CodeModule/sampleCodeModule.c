/* sampleCodeModule.c */
#include <syscallFunctions.h>
#include <shellMovement.h>
#include <libc.h>

#define CHARACTER_COLOR 0xB0CA07

static Cursor cursor;

int main(void){
    char * buffer;
    char c;
	
    inicializeCursor(&cursor);

    call_draw_char('u', 0xFFFFFF, 8, 8, 1);
    call_draw_char('s', 0xFFFFFF, 8*2, 8, 1);
    call_draw_char('e', 0xFFFFFF, 8*3, 8, 1);
    call_draw_char('r', 0xFFFFFF, 8*4, 8, 1);
    call_draw_char('>', 0x0000FF, 8*5, 8, 1);

    while((c=getChar())!='\n'){
        *buffer = c;
        buffer++;
        call_draw_char(c, CHARACTER_COLOR, cursor.x, cursor.y, cursor.scale);
		moveCursor(&cursor, WRITE);
    }
	return 0;

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
