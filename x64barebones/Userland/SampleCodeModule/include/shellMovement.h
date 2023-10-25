#ifndef SHELL_MOVEMENT_H
#define SHELL_MOVEMENT_H

#define MAX_X 1000
#define MAX_Y 1000
#define MIN_X 4
#define MIN_Y 4
#define WIDTH_FONT 8
#define HEIGHT_FONT 16

typedef enum {WRITE=0, DELETE, ENTER}actionOfCursor;

typedef struct {
    int x;
    int y;
    int scale; //size of font in pixel
}Cursor;

void moveCursor(Cursor * cursor, actionOfCursor movement);

#endif