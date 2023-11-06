#include <snake.h>

static char collision(snake * s);
static void resetSquare(int x, int y);
static void drawSnakeHead(snake * s);
static char collision(snake * s);
static char ateFood(snake * s);

static char boardStatus[X_SQUARES][Y_SQUARES] = {{EMPTY}};

char moveSnake(snake * s, direction direction){
    switch(direction){
        case UP: // Up v
            s->head[1] = s->head[1] - 1;
            if(collision(s)){
                return 1;
            }
            s->lastMove = UP;
            printSnake(s);
            break;
        case DOWN: // Down ^
            s->head[1] = s->head[1] + 1;
            if(collision(s)){
                return 1;
            }
            s->lastMove = DOWN;
            printSnake(s);
            break;
        case LEFT: // Left ->
            s->head[0] = s->head[0] - 1;
            if(collision(s)){
                return 1;
            }
            s->lastMove = LEFT;
            printSnake(s);
            break;
        case RIGHT: // Right <-
            s->head[0] = s->head[0] + 1; // x + 1 right in the x axis
            if(collision(s)){
                return 1;
            }
            s->lastMove = RIGHT;
            printSnake(s);
            break;
        default: // continue moving in the same direction
            moveSnake(s, s->lastMove);
            break;
    }
    return 0;
}

void moveTwoSnake(snake * s1, snake * s2, direction direction1, direction direction2){
    char c1,c2;

    c1 = moveSnake(s1, direction1);
    c2 = moveSnake(s2, direction2);

    if(c1){
        lostGame(1);
    }else if (c2){
        lostGame(2);
    }
}

void printSnake(snake * s){
    drawSnakeHead(s);
    if(ateFood(s)){
        s->length++;
        return;
    }
    resetSquare(s->tail[0], s->tail[1]);
    return;
}

snake * createSnake(direction direction){
    snake * s;
    switch (direction) {
        case UP:
            s->head[0] = X_SQUARES - 1;
            s->head[1] = Y_SQUARES - 1;
            s->tail[0] = X_SQUARES - 1;
            s->tail[1] = Y_SQUARES - MIN_SNAKE_LENGTH;
            for (int i = s->tail[1]; i <= s->head[1]; i++) {
                boardStatus[i][0] = SNAKE;
                call_draw_square(s->color, PIXEL_POS(s->tail[0]), PIXEL_POS(i), SQUARE_SIZE);
            }
            break;
        case DOWN:
            s->head[0] = 0;
            s->head[1] = 1; // Since row 0 is the top of the menu bar
            s->tail[0] = 0;
            s->tail[1] = MIN_SNAKE_LENGTH;
            for (int i = s->tail[1]; i >= s->head[1]; i--) {
                boardStatus[X_SQUARES - 1][i] = SNAKE;
                call_draw_square(s->color, PIXEL_POS(X_SQUARES - 1), PIXEL_POS(i), SQUARE_SIZE);
            }
            break;
        case LEFT:
            s->head[0] = X_SQUARES - MIN_SNAKE_LENGTH;
            s->head[1] = Y_SQUARES / 2 - 1;
            s->tail[0] = X_SQUARES - 1;
            s->tail[1] = s->head[1];
            for (int i = s->tail[0]; i >= s->head[0]; i--) {
                boardStatus[i][s->head[1]] = SNAKE;
                call_draw_square(s->color, PIXEL_POS(i), PIXEL_POS(s->tail[1]), SQUARE_SIZE);
            }
            break;
        case RIGHT:
            s->head[0] = MIN_SNAKE_LENGTH - 1;
            s->head[1] = Y_SQUARES / 2 + 1;
            s->tail[0] = 0;
            s->tail[1] = s->head[1];
            for (int i = s->tail[0]; i <= s->head[0]; i++) {
                boardStatus[i][X_SQUARES - 1] = SNAKE;
                call_draw_square(s->color, PIXEL_POS(i), PIXEL_POS(s->tail[1]), SQUARE_SIZE);
            }
            break;
        default:
            break;
    }
    s->length = MIN_SNAKE_LENGTH;
    return s;
}

static char collision(snake * s){
    if(boardStatus[s->head[1]][s->head[0]] == SNAKE){ // Collision with its self
        return 1;
    }
    else if(s->head[0] < 0 || s->head[0] > X_SQUARES || s->head[1] < 0 || s->head[1] > Y_SQUARES){ // Collision with the wall
        return 1;
    }
    return 0;
}

static void resetSquare(int x, int y){
    if((x%2 && y%2) || (x%2 == 0 && y%2 == 0)){
        call_draw_square(PALE_BLUE, PIXEL_POS(x), PIXEL_POS(y), SQUARE_SIZE);
    }else{
        call_draw_square(PALE_BLUE_LIGHTER, PIXEL_POS(x), PIXEL_POS(y), SQUARE_SIZE);
    }
    boardStatus[x][y] = EMPTY;
}

static void drawSnakeHead(snake * s){
    call_draw_square(s->color, s->head[0], s->head[1], SQUARE_SIZE);
    boardStatus[s->head[1]][s->head[0]] = SNAKE;
    return;
}

static char ateFood(snake * s){
    if (s->head[0] == getFood()->x && s->head[1] == getFood()->y) {
        createFood(); // generates a new food
        return 1;
    }
    return 0;
}
