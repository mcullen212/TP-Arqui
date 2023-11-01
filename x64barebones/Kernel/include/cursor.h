#ifndef CURSOR_H
#define CURSOR_H

#define MAX_X 1008
#define MAX_Y 1008
#define MIN_X 8
#define MIN_Y 8
#define WIDTH_FONT 8
#define HEIGHT_FONT 16

typedef enum {WRITE=0, DELETE, ENTER, TAB}actionOfCursor;

typedef struct {
    int x, y, scale;
}Cursor;

void initializeCursor(int x, int y, int scale);
void moveCursor(actionOfCursor action);

uint32_t getCursorX();
uint32_t getCursorY();
uint32_t getCursorScale();
void setCursorScale(int scale);

void drawCharOnCursor(uint8_t character);
void deleteCharOnCursor();
void drawStringOnCursor(uint8_t * string, uint32_t * length);

#endif
