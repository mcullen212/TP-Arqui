#include <snake.h>

void screen(){

}

void inputPlayer1(snake * s){ // que mov tiene la serpiente
    char c = getChar();
    switch(c){
        case 'q': // quit game
            quitGame();
            break;
        case 'i':
            moveSnake(s, UP);
            break;
        case 'k':
            moveSnake(s, DOWN);
            break;
        case 'j':
            moveSnake(s, LEFT);
            break;
        case 'l':
            moveSnake(s, RIGHT);
            break;
        default:
            // do nothing
            break;
    }
}

void inputPlayer2(snake * s){
    char c = getChar();
    switch(c){
        case 'q': // quit game
            quitGame();
            break;
        case 'w':
            moveSnake(s, UP);
            break;
        case 's':
            moveSnake(s, DOWN);
            break;
        case 'a':
            moveSnake(s, LEFT);
            break;
        case 'd':
            moveSnake(s, RIGHT);
            break;
        default:
            // do nothing
            break;
    }
}

void snakeMenu() {
    //call_color_screen(0x0000FFFF); // Pains screen of some color
    //call_c_init(MIN_X, MIN_Y, SCALE);
    printf("Welcome to Snake Game!\nSelec amount of players: (1 or 2)");
    char c;
    do {
        c = getChar();
    } while ( c != '1' || c != '2' );
}

void snakeGame(){
    // snake * s1 = createSnake();
    // snake * s2 = createSnake();
    // while(1){
    //     input(1, s1);
    //     input(2, s2);
    // }
    // amount of players
}

void quitGame(){
    // quit game
}

void moveSnake(snake * s, direction direction) {

}
