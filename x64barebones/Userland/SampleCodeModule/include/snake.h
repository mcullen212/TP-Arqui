#ifndef SNAKE_H
#define SNAKE_H

#include <stdint.h>
#include <libc.h>
#include <syscallFunctions.h>

//snake
#define MIN_SNAKE_LENGTH 5
#define MAX_SNAKE_LENGTH 100

//pixel positions
#define Y_MAX 768
#define X_MAX 1024
#define PIXEL_POS_X(i) (i) * SQUARE_SIZE
#define PIXEL_POS_Y(i) (i + 1) * SQUARE_SIZE

//board positions
#define SQUARE_SIZE 32
#define X_SQUARES (X_MAX / SQUARE_SIZE) // 32
#define Y_SQUARES (Y_MAX / SQUARE_SIZE ) // 24

//menu positions
#define MENU_PLAYER_1 704
#define MENU_PLAYER_2 936
#define MENU 96
#define MENU_WIDTH 
#define MENU_HEIGHT 32
#define MENU_SCALE 1

//board status
#define SNAKE_PLAYER_1 '#'
#define SNAKE_PLAYER_2 '@'
#define FOOD '*'
#define EMPTY '\0'

//colors
#define BOARD_COLORS 3
#define SNAKE_COLORS 4
#define FOOD_TYPES 4


typedef enum{ UP = 0, DOWN, LEFT, RIGHT } direction;

typedef enum {
    PALE_BLUE = 0xADD8E6, // Light Pale Blue
    PALE_BLUE_LIGHTER = 0x87CEEB, // Slightly Darker Pale Blue
    PALE_YELLOW = 0xD4DF73, // Light Pale Yellow
    PALE_YELLOW_LIGHTER = 0xFFFFD9, // Slightly Darker Pale Yellow
    PALE_GREEN  = 0xB7EA9D, // Light Pale Green
    PALE_GREEN_LIGHTER  = 0xEBFFD1 // Slightly Darker Pale Green
} boardColors;

typedef enum {
    SNAKE_BLUE      = 0x0000FF,
    SNAKE_YELLOW    = 0xFFFF00,
    SNAKE_MAGENTA   = 0xFF00FF,
    SNAKE_CYAN      = 0x00FFFF,
} snakeColors;

typedef enum  {
    APPLE = 0xFF0000, // Red
    STRAWBERRY = 0xFFC0CB, // Pink
    WATERMELON = 0xFF1493, // Dark Pink
    CHERRY = 0x8B0000, // Dark Red
} foodColors;

typedef struct point{
    int x;
    int y;
} point;

typedef struct { // Snake coordinates in the board
    point head; //{x,y}
    point body[MAX_SNAKE_LENGTH];
    int length; // length of the snake (number of squares)
    uint32_t color;
    direction lastMove;
    int points;
    char playerReference;
} snake;

typedef struct { // Food coordinates in the board
    foodColors color;
    point position; //{x,y}
} food;

// Food ------------------------------------------------

void createFood();
void printFood();

// -----------------------------------------------------

// Snake -----------------------------------------------

void createSnake(snake * s, uint32_t color, int player);
char moveSnake(snake * s, direction direction);
void printSnake(snake * s);
// -----------------------------------------------------

// Game ------------------------------------------------
void snakeNewGame();
void snakeGame();
int getPlayers();
void quitGame();
void lostGame(int player, snake * s1, snake * s2);
void scoreStatus(snake * s1, snake * s2);
void createBoard();
char ** getBoardStatus();
void updateBoard(snake * s1, snake * s2);
void printBoard(snake * s1, snake * s2);

// -----------------------------------------------------

#endif
