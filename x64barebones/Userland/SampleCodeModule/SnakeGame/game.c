#include <snake.h>

static void pointsTab(int player1, int player2);
static char inputPlayer1(snake * s);
static char inputPlayer2(snake * s1, snake * s2);

static int points[2] = {0,0};
static int players = 1;
static char exit = 0;

void screen(){ // ymax = 768 xmax = 1024
    pointsTab(0, 0);

    for(int i = 0; i < X_SQUARES; i++){ // x
        for(int j = 1; j < Y_SQUARES; j++){ // y  skip first row because it is the menu
            if((j%2 && i%2) || (j%2 == 0 && i%2 == 0)){
                call_draw_square(PALE_GREEN, PIXEL_POS(i), PIXEL_POS(j), 32);
            }else{
                call_draw_square(PALE_GREEN_LIGHTER, PIXEL_POS(i), PIXEL_POS(j), 32);
            }
        }
    }
}

static void pointsTab(int player1, int player2) {
    printf("ESC to quit game \t\t");
    printf("turn off CAPS-LOCK \t\t");
    if(players == 2){
        printf("\tPoints player 1: %d \t", player1);
        printf("\t Points player 2: %d \t", player2);
    }else{
        printf("\tPoints player: %d \t", player1);
    }
}

static char inputPlayer1(snake * s){ // que mov tiene la serpiente
    int readBytes;
    char c = readChar(&readBytes);
    char lost = 0;
    if(readBytes){
        switch(c){
            case 27: // quit game (ESC)
                exit = 1;
                break;
            case 'w':
                lost = moveSnake(s, UP);
                break;
            case 's':
                lost = moveSnake(s, DOWN);
                break;
            case 'a':
                lost = moveSnake(s, LEFT);
                break;
            case 'd':
                lost = moveSnake(s, RIGHT);
                break;
            default:
                //call_sleep(500);
                lost = moveSnake(s, s->lastMove);
                break;
        }
    } else {
        //call_sleep(1000);
        lost = moveSnake(s, s->lastMove);
    }
    return lost;
}

static char inputPlayer2(snake * s1, snake * s2){
    int readBytes, aux;
    char c = readChar(&readBytes);
    char lost = 0;
    if(readBytes){
        switch(c){
            case 27: // quit game (ESC)
                exit = 1;
                break;
            case 'w':
                lost = moveSnake(s1, UP);
                break;
            case 's':
                lost = moveSnake(s1, DOWN);
                break;
            case 'a':
                lost = moveSnake(s1, LEFT);
                break;
            case 'd':
                lost = moveSnake(s1, RIGHT);
                break;
            case 'i':
                lost = moveSnake(s2, UP)? 2 : 0;
                break;
            case 'k':
                lost = moveSnake(s2, DOWN)? 2 : 0;
                break;
            case 'j':
                lost = moveSnake(s2, LEFT)? 2 : 0;
                break;
            case 'l':
                lost = moveSnake(s2, RIGHT)? 2 : 0;
                break;
            default:
                call_sleep(500);
                aux = moveSnake(s1, s1->lastMove);
                lost = moveSnake(s2, s2->lastMove);
                lost = (aux > lost)? aux : lost;
                break;
        }
    }else{
        call_sleep(500);
        aux = moveSnake(s1, s1->lastMove);
        lost = moveSnake(s2, s2->lastMove);
        lost = (aux > lost)? aux : lost;
    }
    return lost;
}

int snakeMenu() {
    printf("Welcome to Snake Game!\nSelect amount of players: (1 or 2)");
    char c,t;
    do {
        c = getChar();
    } while ( c != '1' && c != '2' );
    //scanf("%d", &players);
    return c - '0';
}

void lostGame(int player){ // cartel
    call_clear_screen();
    if(players == 2){
        printf("Player %d lost the game, Player %d WON!!\n", player, player%2 + 1);
        printf("Score Player 1: %d\n", points[0]);
        printf("Score Player 2: %d\n", points[1]);
        printf("Press any key to play again or ESC to quit game\n");
    }else{
        printf("You lost the game, try again!\n\n");
        printf("Score: %d\n", points[0]);
        printf("Press any key to play again or ESC to quit game\n");
    }

    char c = getChar();

    if(c == 27){
        exit = 1;
        quitGame();
    }else{
        snakeGame();
    }
    
}

int score(snake * s){
    return s->length - MIN_SNAKE_LENGTH;
}

void scoreStatus(){
    if(players == 2){
        printf("Score Player 1: %d\n", points[0]);
        printf("Score Player 2: %d\n", points[1]);
    }else{
        printf("Score: %d\n", points[0]);
    }
}

void snakeGame(){
    exit = 0;
    call_clear_screen();
    players = snakeMenu();
    call_clear_screen();
    screen();
    createBoard();
    call_sleep(3000);

    snake snakeP1, snakeP2 ;

    createSnake(&snakeP1, SNAKE_BLUE, 1);

    if(players == 2){
        createSnake(&snakeP2, SNAKE_YELLOW, 2);
    }

    char p1, p2;
    createFood();

    while(exit != 1){
        if(players == 1){
            p1 = inputPlayer1(&snakeP1);
        } else {
            p2 = inputPlayer2(&snakeP1, &snakeP2);
            points[1] = score(&snakeP2);
        }
        points[0] = score(&snakeP1);
        
        scoreStatus(); // print current score of the game

        if(p1 || p2){
            if(players == 2){
                lostGame(p2);
                return;
            }
            lostGame(p1);
        }
    }   
    quitGame();
}

void quitGame(){
    call_clear_screen();
    printf("Thanks for playing!\n");
    printf("Press any key to return to terminal...\n");
    getChar();
    call_clear_screen();
    return;
}

int getPlayers(){
    return players;
}
