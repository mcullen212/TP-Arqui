#include <snake.h>
#include <foods.h>
#include <syscallFunctions.h>

void screen(){ // ymax = 768 xmax = 1024
    // squares 16 x 16 pixels  => 64 x 48 squares 
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            //need to create checkers 
            if((j%2 && i%2) || (j%2 == 0 && i%2 == 0)){
                call_draw_square(PALE_BLUE, i*32, j*32, 32);
                call_draw_circle(APPLE, i*32, j*32, 32);
            }else{
                call_draw_square(PALE_BLUE_LIGHTER, i*32, j*32, 32);
            }
        }
    }

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
    screen();
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
