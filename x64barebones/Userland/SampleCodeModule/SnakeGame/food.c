#include <snake.h>

static food * currentFood;

static uint32_t * foodType = {APPLE, BANANA, STRAWBERRY, WATERMELON, PINEAPPLE, CHERRY};

void createFood(){
    char boardStatusCopy[Y_SQUARES][X_SQUARES] = getBoardStatus();
    int xCoord, yCoord;
    do {
        xCoord = rand(0, X_SQUARES-1);
        yCoord = rand(1,Y_SQUARES-1);

    } while (boardStatusCopy[yCoord][xCoord] != EMPTY);
    currentFood->position.x = xCoord;
    currentFood->position.y = yCoord;
    currentFood->color = foodType[rand(0,FOOD_TYPES - 1)];
}

food * getFood(){
    return currentFood;
}
