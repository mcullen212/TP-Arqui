#include <snake.h>

static char collision(snake * s);
static void resetSquare(int x, int y);
static void drawSnakeHead(snake * s);
static char collision(snake * s);

char move(snake * s, direction direction){
    switch(direction){
        case UP: // Up v
            s->head[1] = s->head[1] - SQUARE_SIZE;
            if(collision(s)){
                return 1;
            }
            s->lastMove = UP;
            printSnake(s);
            break;
        case DOWN: // Down ^
            s->head[1] = s->head[1] + SQUARE_SIZE;
            if(collision(s)){
                return 1;
            }
            s->lastMove = DOWN;
            printSnake(s);
            break;
        case LEFT: // Left ->
            s->head[0] = s->head[0] - SQUARE_SIZE;
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
            move(s, s->lastMove);
            break;
    }
    return 0;
}

void moveTwoSnake(snake * s1, snake * s2, direction direction1, direction direction2){
    char c1,c2;

    c1 = move(s1, direction1);
    c2 = move(s2, direction2);

    if(c1){
        lostGame(1);
    }else if (c2){
        lostGame(2);
    }
}

int score(snake * s){
    return s->length - MIN_SNAKE_LENGTH;
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

static char collision(snake * s){
    if(boardStatus[s->head[1]][s->head[0]] == SNAKE){ // Collision with its self
        return 1;
    }
    else if(s->head[0] < 0 || s->head[0] > X_MAX || s->head[1] < 0 || s->head[1] > Y_MAX){ // Collision with the wall
        return 1;
    }
    return 0;
}

static void resetSquare(int x, int y){
    if((x%2 && y%2) || (x%2 == 0 && y%2 == 0)){
        call_draw_square(PALE_BLUE, x*SQUARE_SIZE, y*SQUARE_SIZE, SQUARE_SIZE);
    }else{
        call_draw_square(PALE_BLUE_LIGHTER, x*SQUARE_SIZE, y*SQUARE_SIZE, SQUARE_SIZE);
    }
    boardStatus[y][x] = EMPTY;
}

static void drawSnakeHead(snake * s){
    call_draw_square(s->color, s->head[0], s->head[1], SQUARE_SIZE);
    boardStatus[s->head[1]][s->head[0]] = SNAKE;
    return;
}

static char ateFood(snake * s){ 
    if (s->head[0] == food->x && s->head[1] == food->y) {
        createFood(); // generates a new food
        return 1;
    }
    return 0;
}