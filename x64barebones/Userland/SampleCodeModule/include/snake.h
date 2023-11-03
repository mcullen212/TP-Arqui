#ifndef SNAKE_H
#define SNAKE_H

#include <stdint.h>
#include <libc.h>

typedef enum{ UP = 0, DOWN, LEFT, RIGHT } direction;

enum boardColors {
    PALE_BLUE      = 0xADD8E6, // Light Pale Blue
    PALE_BLUE_LIGHTER     = 0x87CEEB, // Slightly Darker Pale Blue
};

// enum Hex32Colors {
//     COLOR_BLACK     = 0x000000,
//     COLOR_WHITE     = 0xFFFFFF,
//     COLOR_RED       = 0xFF0000,
//     COLOR_GREEN     = 0x00FF00,
//     COLOR_BLUE      = 0x0000FF,
//     COLOR_YELLOW    = 0xFFFF00,
//     COLOR_MAGENTA   = 0xFF00FF,
//     COLOR_CYAN      = 0x00FFFF,
//     COLOR_GRAY      = 0x808080,
//     COLOR_LIGHT_GRAY = 0xC0C0C0,
//     COLOR_DARK_GRAY  = 0x404040,
// };

// enum Hex32Colors themesSnake[][4] ={ // {backgroundColor, foodColor, player1, player2}
//     {COLOR_BLACK, COLOR_RED, COLOR_WHITE, COLOR_CYAN},
//     {COLOR_BLACK, COLOR_YELLOW, COLOR_BLUE, COLOR_RED},
//     {COLOR_BLACK, COLOR_CYAN, COLOR_WHITE, COLOR_RED},
//     {COLOR_WHITE, COLOR_BLACK, COLOR_RED, COLOR_BLUE},
//     {COLOR_WHITE, COLOR_BLUE, COLOR_RED, COLOR_YELLOW}
// };

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
void quitGame();

#endif
