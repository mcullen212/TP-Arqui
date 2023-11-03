#include <snake.h>

// int collision(){

// }

void move(snake * s, direction direction){
    switch(direction){
        case UP: // Up v
            s->head[1] = s->head[1] - 1;
            printSnake(s);
            break;
        case DOWN: // Down ^
            s->head[1] = s->head[1] + 1;
            printSnake(s);
            break;
        case LEFT: // Left ->
            s->head[0] = s->head[0] - 1;
            printSnake(s);
            break;
        case RIGHT: // Right <-
            s->head[0] = s->head[0] + 1;
            printSnake(s);
            break;
    }
}

void printSnake(snake * s){
    for (int i = 0; i < s->length; i++) {
        //drawSquare(s->color, s->body[i][0], s->body[i][1], 1);
    }
}
