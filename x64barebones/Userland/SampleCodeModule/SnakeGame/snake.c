#include <snake.h>

#define X 0
#define Y 1

static char collision(snake * s);
static char ateFood(snake * s);
static void updateBody(snake * s);
static void updateBodyAfterMeal(snake * s);

void createSnake(snake * s, uint32_t color, int player) {
    char ** boardStatus;
    boardStatus = getBoardStatus();
    // Player 1 initialization
    if(player == 1){
        s->playerReference = SNAKE_PLAYER_1;
        s->color = color;
        s->head.x = MIN_SNAKE_LENGTH - 1;
        s->head.y = Y_SQUARES / 2 + 1;
        for(int i = 0; i <= s->head.x; i++){ // Tail (x,y) is the first element of "body" array.
            s->body[i].x = i;
            s->body[i].y = s->head.y;
            boardStatus[i][s->head.y] = s->playerReference;
        }
        s->length = MIN_SNAKE_LENGTH;
        s->lastMove = RIGHT;
        s->points = 0;
        return;
    }
    // Player 2 initialization
    s->playerReference = SNAKE_PLAYER_2;
    s->color = color;
    s->head.x = X_SQUARES-MIN_SNAKE_LENGTH;
    s->head.y = Y_SQUARES / 2 - 1;
    for(int i = X_SQUARES-1; i >= s->head.x; i--){ // Tail (x,y) is the first element of "body" array.
        s->body[i].x = i;
        s->body[i].y = s->head.y;
        boardStatus[i][s->head.y] = s->playerReference;
    }
    s->length = MIN_SNAKE_LENGTH;
    s->lastMove = LEFT;
    s->points = 0;
}

char moveSnake(snake * s, direction direction){
    switch(direction){
        case UP: // Up ^
            s->head.y -= 1; // Head update
            if(collision(s)){
                return 1;
            }
            s->lastMove = UP;
            break;
        case DOWN: // Down v
            s->head.y += 1;  // Head update
            if(collision(s)){
                return 1;
            }
            s->lastMove = DOWN;
            break;
        case LEFT: // Left ->
            s->head.x += 1; // Head update
            if(collision(s)){
                return 1;
            }
            s->lastMove = LEFT;
            break;
        case RIGHT: // Right <-
            s->head.x -= 1;
            if(collision(s)){
                return 1;
            }
            s->lastMove = RIGHT;
            break;
        default:
            break;
    }
    if (ateFood(s)) {
        updateBodyAfterMeal(s);
        updateBoardFromFood(getFood());
        return 0;
    }
    updateBody(s);
    return 0;
}

static char collision(snake * s){
    char ** boardStatus;
    boardStatus = getBoardStatus();

    if(boardStatus[s->head.y][s->head.x] != EMPTY && boardStatus[s->head.y][s->head.x] != FOOD ){ // Collision with its snake
        return 1;
    }
    else if(s->head.x < 0 || s->head.x > X_SQUARES || s->head.y < 1 || s->head.y > Y_SQUARES){ // Collision with the wall
        return 1;
    }
    return 0;
}

static char ateFood(snake * s){
    if (s->head.x == getFood()->position.x && s->head.y == getFood()->position.y) {
        createFood(); // generates a new food
        return 1;
    }
    return 0;
}

static void updateBody(snake * s) {
    int i;
    for (i = 1; i < s->length; i++) {
        s->body[i - 1] = s->body[i];
    }
    s->body[i - 1] = s->head;
}

static void updateBodyAfterMeal(snake * s) {
    s->length++;
    s->body[s->length - 1] = s->head;
}
