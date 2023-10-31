#include <cursor.h>
#include <stdint.h>

static Cursor cursor = {MIN_X, MIN_Y, 1};

Cursor * getCursor() {
    return &cursor;
}

uint32_t getCursorX() {
    return cursor.x;
}

uint32_t getCursorY() {
    return cursor.y;
}

uint32_t getCursorScale() {
    return cursor.scale;
}

static void moveRight() {
    if(cursor.x < (MAX_X - (WIDTH_FONT * cursor.scale))) {
        cursor.x += (WIDTH_FONT * cursor.scale);
        return;
    }

    cursor.x = MIN_X;
    if(cursor.y < MAX_Y){
        cursor.y += (HEIGHT_FONT * cursor.scale);
        return;
    }

    cursor.y = MIN_Y;
    //clearTerminal
}

static void moveLeft() {
    if(cursor.x == MIN_X && cursor.y == MIN_Y) {
        return;
    }
    if(cursor.x == MIN_X) {
        cursor.x = MAX_X-(cursor.scale*WIDTH_FONT);
        cursor.y -= (HEIGHT_FONT * cursor.scale);
        return;
    }
    cursor.x -= (WIDTH_FONT * cursor.scale);
}

static void moveDown() {
    if(cursor.y < MAX_Y){
        cursor.y += (HEIGHT_FONT * cursor.scale);
        cursor.x = MIN_X;
        return;
    }
    cursor.x = MIN_X;
    cursor.y = MAX_Y;
    //clearTerminal

}

void cursorAction(actionOfCursor movement) {
    switch(movement){
        case WRITE :
            moveRight();
            break;
        case DELETE :
            moveLeft();
            break;
        case ENTER :
            moveDown();
            break;
        default :
            break;
    }
}

void moveCursor(uint32_t x, uint32_t y) {
    cursor.x += x;
    cursor.y += y;
}

void setScale(int scale) {
    cursor.scale = scale;
}

