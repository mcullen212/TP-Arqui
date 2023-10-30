/* sampleCodeModule.c */
#include <syscallFunctions.h>
#include <shellMovement.h>
#include <libc.h>
#include <themes.h>

#define CHARACTER_COLOR 0xB0CA07

static Cursor cursor;

int main(void){
    char * buffer;
    char c;
	
    inicializeCursor(&cursor);

    call_set_theme(themes[4][1], themes[4][0]);

    call_draw_char('u', 8, 8, 1);
    call_draw_char('s', 8*2, 8, 1);
    call_draw_char('e', 8*3, 8, 1);
    call_draw_char('r', 8*4, 8, 1);
    call_draw_char('>', 8*5, 8, 1);

    while((c=getChar())!='\n'){
        *buffer = c;
        buffer++;
        call_draw_char(c, cursor.x, cursor.y, cursor.scale);
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
