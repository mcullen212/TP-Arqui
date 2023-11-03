#include <snake.h>

typedef enum{ UP = 0, DOWN, LEFT, RIGHT } direction;

typedef struct { // Snake coordinates
    int head[2];
    int tail[2];
    int length;
} snake;

// int collision(){
    
// }

void move(snake * s, direction direction){
    switch(direction){
        case UP: // Up v
            s->head[1] = s->head[1] - 1;
            break;
        case DOWN: // Down ^
            s->head[1] = s->head[1] + 1;
            break;
        case LEFT: // Left ->
            s->head[0] = s->head[0] - 1;
            break;
        case RIGHT: // Right <-
            s->head[0] = s->head[0] + 1;
            break;
    }
}