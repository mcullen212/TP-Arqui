#include <shellMovement.h>
#include <stdint.h>

void inicializeCursor(Cursor * cursor) {
    cursor->x = MIN_X;
    cursor->y = MIN_Y;
    cursor->scale = 1;
}

static void moveRight(Cursor * cursor) {
    if(cursor->x < MAX_X){
        cursor->x += (WIDTH_FONT * cursor->scale);
        return;
    }

    cursor->x = MIN_X;
    if(cursor->y < MAX_Y){
        cursor->y += (HEIGHT_FONT * cursor->scale);
        return;
    }

    cursor->y = MIN_Y;
    //clearTerminal
}

static void moveLeft(Cursor * cursor) {
    if(cursor->x == MIN_X && cursor->y == MIN_Y) {
        return;
    }
    if(cursor->x == MIN_X) {
        cursor->x = MAX_X;
        cursor->y -= (HEIGHT_FONT * cursor->scale);
        return;
    }
    cursor->x -= (WIDTH_FONT * cursor->scale);
}

static void moveDown(Cursor * cursor) {
    if(cursor->y < MAX_Y){
        cursor->y += (HEIGHT_FONT * cursor->scale);
        cursor->x = MIN_X;
        return;
    }
    cursor->x = MIN_X;
    cursor->y = MAX_Y;
    //clearTerminal

}


void moveCursor(Cursor * cursor, actionOfCursor movement) {
    switch(movement){
        case WRITE :
            moveRight(cursor);
            break;
        case DELETE :
            moveLeft(cursor);
            break;
        case ENTER :
            moveDown(cursor);
            break;
        default :
            break;
    }
}


