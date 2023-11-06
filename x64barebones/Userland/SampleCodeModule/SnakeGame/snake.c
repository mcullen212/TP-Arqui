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

void createSnake(snake * s, uint32_t color, int player) {
    s->color = color; 
    if(player == 1){
        s->head.x = MIN_SNAKE_LENGTH - 1;
        s->head.y = Y_SQUARES / 2 + 1;
        for(int i = 0; i <= s->head.x; i++){ // tail is first
            s->body[i].x = i;
            s->body[i].y = s->head.y;
            boardStatus[i][s->head.y] = SNAKE_PLAYER_1;
        }
        s->length = MIN_SNAKE_LENGTH;
        s->lastMove = RIGHT;
        s->points = 0;
        return;
    }
    
    s->head.x = X_SQUARES-MIN_SNAKE_LENGTH;
    s->head.y = Y_SQUARES / 2 - 1;
    for(int i = X_SQUARES-1; i >= s->head.x; i--){ // tail is first
        s->body[i].x = i;
        s->body[i].y = s->head.y;
        boardStatus[i][s->head.y] = SNAKE_PLAYER_2;
    }
    s->length = MIN_SNAKE_LENGTH;
    s->lastMove = LEFT;
    s->points = 0;
}

char moveSnake(snake * s, direction direction){
    switch(direction){
        case UP: // Up v
            s->head[Y] = s->head[Y] - 1;
            if(collision(s)){
                return 1;
            }
            s->lastMove = UP;
            printSnake(s);
            break;
        case DOWN: // Down ^
            s->head[Y] = s->head[Y] + 1;
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
    return;
}



static char collision(snake * s){
    if(boardStatus[s->head[Y]][s->head[X]] == SNAKE){ // Collision with its snake
        return 1;
    }
    else if(s->head[X] < 0 || s->head[X] > X_SQUARES || s->head[Y] < 1 || s->head[Y] > Y_SQUARES){ // Collision with the wall
        return 1;
    }
    return 0;
}

static void resetSquare(int x, int y){
    if((x%2 && y%2) || (x%2 == 0 && y%2 == 0)){
        call_draw_square(PALE_GREEN, PIXEL_POS(x), PIXEL_POS(y), SQUARE_SIZE);
    }else{
        call_draw_square(PALE_GREEN_LIGHTER, PIXEL_POS(x), PIXEL_POS(y), SQUARE_SIZE);
    }
    boardStatus[x][y] = EMPTY;
}

static void drawSnakeHead(snake * s){
    call_draw_square(s->color, PIXEL_POS(s->head[X]), PIXEL_POS(s->head[Y]), SQUARE_SIZE);
    boardStatus[s->head[Y]][s->head[X]] = SNAKE;
    resetSquare(s->tail[X], s->tail[Y]);
    return;
}

static char ateFood(snake * s){
    if (s->head[X] == getFood()->x && s->head[Y] == getFood()->y) {
        createFood(); // generates a new food
        return 1;
    }
    return 0;
}
