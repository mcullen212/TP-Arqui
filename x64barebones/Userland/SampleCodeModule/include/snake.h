#ifndef SNAKE_H
#define SNAKE_H

#include <themes.h>
typedef enum{ UP = 0, DOWN, LEFT, RIGHT } direction;

enum Hex32Colors themes[][4] ={ // {backgroundColor, foodColor, player1, player2}
    {COLOR_BLACK, COLOR_RED, COLOR_WHITE, COLOR_CYAN},
    {COLOR_BLACK, COLOR_YELLOW, COLOR_BLUE, COLOR_RED},
    {COLOR_BLACK, COLOR_CYAN, COLOR_WHITE, COLOR_RED},
    {COLOR_WHITE, COLOR_BLACK, COLOR_RED, COLOR_BLUE},
    {COLOR_WHITE, COLOR_BLUE, COLOR_RED, COLOR_YELLOW}
};

typedef struct { // Snake coordinates
    int head[2]; //{x,y}
    int tail[2];
    int length;
    int lastMoveHead[2];
    int lastMoveTail[2];
} snake;

typedef struct { // Food coordinates
    int x;
    int y;
} food;

snake * createSnake();
void moveSnake(snake * s, direction direction);
void printSnake(snake * s);

void printFood();

void snakeGame();

#endif