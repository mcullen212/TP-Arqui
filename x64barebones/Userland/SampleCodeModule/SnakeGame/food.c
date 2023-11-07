#include <snake.h>

static food * currentFood;

static int foodType[] = {0xFF0000, 0xFFFF00, 0xFFC0CB, 0xFF1493, 0xFFD700, 0x8B0000};

void createFood(){
    char ** boardStatusCopy;
    boardStatusCopy = getBoardStatus();
    int xCoord, yCoord;
    do {
        xCoord = rand(0, X_SQUARES - 1);
        yCoord = rand(1,Y_SQUARES - 1);
    } while (boardStatusCopy[yCoord][xCoord] != EMPTY);

    currentFood->position.x = xCoord;
    currentFood->position.y = yCoord;
    currentFood->color = foodType[rand(0,FOOD_TYPES - 1)];
}

food * getFood(){
    return currentFood;
}
