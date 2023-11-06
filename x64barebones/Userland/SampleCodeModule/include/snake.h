#ifndef SNAKE_H
#define SNAKE_H

#include <stdint.h>
#include <libc.h>
#include <syscallFunctions.h>

#define MIN_SNAKE_LENGTH 5

//menu positions
#define MENU_Y 0
#define MENU_WIDTH 1024
#define MENU_HEIGHT 32

//pixel positions
#define Y_MAX 768
#define X_MAX 1024
#define PIXEL_POS(i) i * SQUARE_SIZE

//board positions
#define SQUARE_SIZE 32
#define X_SQUARES (X_MAX / SQUARE_SIZE) // 32
#define Y_SQUARES (Y_MAX / SQUARE_SIZE ) // 23

//board status
#define SNAKE '#'
#define FOOD '*'
#define EMPTY ' '

typedef enum{ UP = 0, DOWN, LEFT, RIGHT } direction;

typedef enum  {
    PALE_BLUE      = 0xADD8E6, // Light Pale Blue
    PALE_BLUE_LIGHTER     = 0x87CEEB, // Slightly Darker Pale Blue
    PALE_YELLOW    = 0xFFFFE0, // Light Pale Yellow
    PALE_YELLOW_LIGHTER   = 0xFFFFF0, // Slightly Darker Pale Yellow
    PALE_GREEN     = 0xB7EA9D, // Light Pale Green
    PALE_GREEN_LIGHTER    = 0xEBFFD1 // Slightly Darker Pale Green
} boardColors;

typedef enum { 
    SNAKE_GREEN = 0x003B00, 
    SNAKE_BLUE = 0x1A9FFF,
    SNAKE_PURPLE = 0x291AFF, 
    SNAKE_ORANGE = 0xFF791A,
} snakeColors;

typedef enum  {
    APPLE = 0xFF0000, // Red
    BANANA = 0xFFFF00, // Yellow
    STRAWBERRY = 0xFFC0CB, // Pink
    WATERMELON = 0xFF1493, // Dark Pink
    PINEAPPLE = 0xFFD700, // Gold
    CHERRY = 0x8B0000, // Dark Red
} foodColors;

//foodColors[]  {APPLE, BANANA, ORANGE, STRAWBERRY, WATERMELON, PINEAPPLE, CHERRY} foodType;

typedef struct { // Snake coordinates in the board
    int head[2]; //{x,y}
    int tail[2];
    int length; // length of the snake (number of squares)
    snakeColors color;
    direction lastMove;
} snake;

typedef struct { // Food coordinates in the board
    foodColors color;
    int x;
    int y;
} foodPosition;

// Food ------------------------------------------------

foodPosition * getFood();
void createFood();

// -----------------------------------------------------

// Snake -----------------------------------------------

snake * createSnake(direction direction);
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
