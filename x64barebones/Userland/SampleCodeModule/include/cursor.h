#ifndef CURSOR_H
#define CURSOR_H

#include <stdint.h>

#define MAX_X 1008
#define MAX_Y 1008
#define MIN_X 8
#define MIN_Y 8
#define WIDTH_FONT 8
#define HEIGHT_FONT 16

typedef enum {WRITE=0, DELETE, ENTER}actionOfCursor;

typedef struct {
    uint32_t x;
    uint32_t y;
    uint32_t scale; //size of font in pixel
}Cursor;

Cursor * getCursor();
uint32_t getCursorX();
uint32_t getCursorY();
uint32_t getCursorScale();

void setScale(int scale);
void cursorAction(actionOfCursor movement);
void moveCursor(uint32_t x, uint32_t y);

#endif