#ifndef COMMANDS_H
#define COMMANDS_H

#include <syscallFunctions.h>
#include <libc.h>
#include <snake.h>

#define AMOUNT_OF_COMMANDS 9

void man();

// void snake(uint32_t players);
//void snakeGame();

void registers();

void time();

// void setTheme(uint32_t index);

// void setScale(uint32_t scale);

void div0();

void invalidop();

void clear();

void zoomIn();

void zoomOut();

#endif
