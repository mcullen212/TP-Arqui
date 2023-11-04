#ifndef SNAKE_H
#define SNAKE_H

#include <stdint.h>
#include <libc.h>
#include <syscallFunctions.h>

#define MIN_SNAKE_LENGTH 5
#define Y_MAX 768
#define X_MAX 1024
#define SQUARE_SIZE 32

#define X_SQUARES (X_MAX / SQUARE_SIZE)
#define Y_SQUARES (Y_MAX / SQUARE_SIZE)

#define SNAKE '#'
#define FOOD '*'
#define EMPTY ' '

typedef enum{ UP = 0, DOWN, LEFT, RIGHT } direction;

typedef enum  {
    PALE_BLUE      = 0xADD8E6, // Light Pale Blue
    PALE_BLUE_LIGHTER     = 0x87CEEB, // Slightly Darker Pale Blue
    PALE_YELLOW    = 0xFFFFE0, // Light Pale Yellow
    PALE_YELLOW_LIGHTER   = 0xFFFFF0, // Slightly Darker Pale Yellow
    PALE_GREEN     = 0x98FB98, // Light Pale Green
    PALE_GREEN_LIGHTER    = 0x90EE90 // Slightly Darker Pale Green
} boardColors;

typedef enum { // cool colors
    GREEN = 0x00FF00, // Green
    BLUE = 0x0000FF, // Blue
    BLUE_LIGHTER = 0x00FFFF, // Light Blue
    GREEN_LIGHTER = 0x00FF7F, // Light Green
    PURPLE = 0x800080, // Purple
    PURPLE_LIGHTER = 0x8A2BE2, // Light Purple
} snakeColors;

typedef enum  {
    APPLE = 0xFF0000, // Red
    BANANA = 0xFFFF00, // Yellow
    ORANGE = 0xFFA500, // Orange
    STRAWBERRY = 0xFFC0CB, // Pink
    WATERMELON = 0xFF1493, // Dark Pink
    PINEAPPLE = 0xFFD700, // Gold
    CHERRY = 0x8B0000, // Dark Red
} foodColors;

typedef struct { // Snake coordinates
    int head[2]; //{x,y}
    int tail[2];
    int length; // length of the snake (number of squares)
    snakeColors color;
    direction lastMove;
} snake;

typedef struct { // Food coordinates
    foodColors color;
    int x;
    int y;
} foodPosition;

// Food ------------------------------------------------

foodPosition * getFood();
void createFood();

// -----------------------------------------------------

// Snake -----------------------------------------------

snake * createSnake();
char moveSnake(snake * s, direction direction);
void moveTwoSnake(snake * s1, snake * s2, direction direction1, direction direction2);
void printSnake(snake * s);

// -----------------------------------------------------

// Game ------------------------------------------------

void snakeGame();
int getPlayers();
void quitGame();
void lostGame(int player);

// -----------------------------------------------------

#endif
