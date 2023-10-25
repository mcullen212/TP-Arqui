/* sampleCodeModule.c */
#include <syscallFunctions.h>
#include <shellMovement.h>
#include <libc.h>

#define CHARACTER_COLOR 0xB0CA07


int main(void){
    char * buffer;
    char c;
    call_draw_char('>', CHARACTER_COLOR, MIN_X, MIN_Y, 3);
	Cursor cursor;
	cursor.x = MIN_X;
	cursor.y = MIN_Y;
	cursor.scale = 3;

    while((c=getChar())!='\n'){
        *buffer++ = c;
        call_draw_char(c, CHARACTER_COLOR, cursor.x, cursor.y, cursor.scale);
		moveCursor(&cursor, WRITE);
    }

	return 0;

}

// char * v = (char*)0xB8000 + 79 * 2;

// static int var1 = 0;
// static int var2 = 0;


// int main() {
// 	//All the following code may be removed 
// 	*v = 'X';
// 	*(v+1) = 0x74;

// 	//Test if BSS is properly set up
// 	if (var1 == 0 && var2 == 0)
// 		return 0xDEADC0DE;

// 	return 0xDEADBEEF;
// }