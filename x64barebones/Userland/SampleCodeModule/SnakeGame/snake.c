#include <snake.h>

#define X 0
#define Y 1

static char collision(snake * s);
static void resetSquare(int x, int y);
static void drawSnakeHead(snake * s);
static char collision(snake * s);
static char ateFood(snake * s);

static char boardStatus[Y_SQUARES][X_SQUARES];

void createBoard(){
    for(int i = 0; i < Y_SQUARES; i++){
        for(int j = 0; j < X_SQUARES; j++){
            boardStatus[i][j] = EMPTY;
        }
    }
}

char moveSnake(snake * s, direction direction){
    switch(direction){
        case UP: // Up v
            s->head[Y] = s->head[Y] + 1;
            if(collision(s)){
                return 1;
            }
            s->lastMove = UP;
            printSnake(s);
            break;
        case DOWN: // Down ^
            s->head[Y] = s->head[Y] - 1;
            if(collision(s)){
                return 1;
            }
            s->lastMove = DOWN;
            printSnake(s);
            break;
        case LEFT: // Left ->
            s->head[X] = s->head[X] + 1;
            if(collision(s)){
                return 1;
            }
            s->lastMove = LEFT;
            printSnake(s);
            break;
        case RIGHT: // Right <-
            s->head[X] = s->head[X] - 1; // x + 1 right in the x axis
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

void printSnake(snake * s){
    drawSnakeHead(s);
    if(ateFood(s)){
        s->length++;
        return;
    }
    resetSquare(s->tail[0], s->tail[1]);
    return;
}

void createSnake(snake * s, direction direction) {
    switch (direction) {
        case UP:
            s->head[X] = X_SQUARES - 1;
            s->head[Y] = Y_SQUARES - MIN_SNAKE_LENGTH;
            s->tail[X] = X_SQUARES - 1;
            s->tail[Y] = Y_SQUARES - 1;
            for (int i = s->tail[Y]; i >= s->head[Y]; i--) {
                boardStatus[i][X_SQUARES-1] = SNAKE;
                call_draw_square(s->color, PIXEL_POS(X_SQUARES-1), PIXEL_POS(i), SQUARE_SIZE);
            }
            s->lastMove = UP;
            break;
        case DOWN:
            s->head[X] = 0;
            s->head[Y] = MIN_SNAKE_LENGTH; 
            s->tail[X] = 0;                    // Since row 0 is the top of the menu bar
            s->tail[Y] = 1;
            for (int i = s->tail[Y]; i <= s->head[Y]; i++) {
                boardStatus[i][0] = SNAKE;
                call_draw_square(s->color, PIXEL_POS(0), PIXEL_POS(i), SQUARE_SIZE);
            }
            s->lastMove = DOWN;
            break;
        case LEFT:
            s->head[X] = X_SQUARES - MIN_SNAKE_LENGTH;
            s->head[Y] = Y_SQUARES / 2 - 1;         //Upper middle screen
            s->tail[X] = X_SQUARES - 1;
            s->tail[Y] = s->head[Y];
            for (int i = s->tail[X]; i >= s->head[X]; i--) {
                boardStatus[s->head[Y]][i] = SNAKE;
                call_draw_square(s->color, PIXEL_POS(i), PIXEL_POS(s->tail[Y]), SQUARE_SIZE);
            }
            s->lastMove = LEFT;
            break;
        case RIGHT:
            s->head[X] = MIN_SNAKE_LENGTH - 1;
            s->head[Y] = Y_SQUARES / 2 + 1;
            s->tail[X] = 0;
            s->tail[Y] = s->head[Y];
            for (int i = s->tail[X]; i <= s->head[X]; i++) {
                boardStatus[s->head[Y]][i] = SNAKE;
                call_draw_square(s->color, PIXEL_POS(i), PIXEL_POS(s->head[Y]), SQUARE_SIZE);
            }
            s->lastMove = RIGHT;
            break;
        default:
            break;
    }
    s->length = MIN_SNAKE_LENGTH;
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
