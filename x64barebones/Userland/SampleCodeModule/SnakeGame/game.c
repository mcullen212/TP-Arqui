#include <snake.h>

static void pointsTab(int player1, int player2);

static int points[2] = {0,0};
static int players = 1;

void screen(){ // ymax = 768 xmax = 1024
    // Squares 16 x 16 pixels  => 64 x 48 squares
    pointsTab(0, 0);

    for(int i = 0; i < X_SQUARES; i++){ // x
        for(int j = 1; j < Y_SQUARES; j++){ // y  salto primer linea ya que es para el menu
            //need to create checkers
            if((j%2 && i%2) || (j%2 == 0 && i%2 == 0)){
                call_draw_square(PALE_BLUE, PIXEL_POS(i), PIXEL_POS(j), 32);
            }else{
                call_draw_square(PALE_BLUE_LIGHTER, PIXEL_POS(i), PIXEL_POS(j), 32);
            }
        }
    }
}

static void pointsTab(int player1, int player2) {
    printf("SHIFT + X to quit game \t\t");
    printf("turn off CAPS-LOCK \t\t");
    if(players == 2){
        printf("\tPoints player 1: %d \t", player1);
        printf("\t Points player 2: %d \t", player2);
    }else{
        printf("\tPoints player: %d \t", player1);
    }
}

void inputPlayer1(snake * s){ // que mov tiene la serpiente
    char c = getChar();
    switch(c){
        case 'X': // quit game SHIFT + X
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
        case 'S': // quit game
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
        printf("Press any key to continue...\n");
    }else{
        printf("You lost the game, try again!\n\n");
        printf("Score: %d\n", points[0]);
        printf("Press any key to continue...\n");
    }
    quitGame();
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
    call_clear_screen();
    players = snakeMenu();
    call_clear_screen();
    screen();
    // snake * s1 = createSnake();
    // snake * s2 = createSnake();
    // createFood();
    // while(1){
    //     input(1, s1);
    //     input(2, s2);
    //     moveTwoSnake(s1, s2, s1->lastMove, s2->lastMove);
    //     points[0] = score(s1);
    //     points[1] = score(s2);
    //     scoreStatus(); // print current score of the game
    // }
    // amount of players
}

void quitGame(){
    // quit game
}

int getPlayers(){
    return players;
}
