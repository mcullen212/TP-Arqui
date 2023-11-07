#include <snake.h>

static void screen();
static void pointsTab(int player1, int player2);
static char inputPlayer1(snake * s);
static char inputPlayer2(snake * s1, snake * s2);

static char boardStatus[Y_SQUARES][X_SQUARES];

static int players = 1;
static char exit = 0;

static uint32_t boardTheme[3][2] = {
    {PALE_BLUE, PALE_BLUE_LIGHTER},
    {PALE_YELLOW, PALE_YELLOW_LIGHTER},
    {PALE_GREEN, PALE_GREEN_LIGHTER}
};

void snakeGame(){
    exit = 0;
    call_clear_screen();
    players = snakeMenu();
    call_clear_screen();
    screen();
    createBoard();
    call_sleep(3000);

    snake snakeP1, snakeP2;

    createSnake(&snakeP1, SNAKE_BLUE, 1);

    if(players == 2){
        createSnake(&snakeP2, SNAKE_YELLOW, 2);
    }

    char p1, p2;
    createFood();

    while(exit != 1){
        if(players == 1){
            p1 = inputPlayer1(&snakeP1);
            scoreStatus(&snakeP1, NULL); // print current score of the game
        } else {
            p2 = inputPlayer2(&snakeP1, &snakeP2);
            scoreStatus(&snakeP1, &snakeP2); // print current score of the game
        }
        
        if(p1 || p2){
            if(players == 2){
                lostGame(p2, &snakeP1, &snakeP2);
                return;
            }
            lostGame(p1, &snakeP1, &snakeP2);
        }
    }   
    quitGame();
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

void createBoard(){
    for(int i = 0; i < Y_SQUARES; i++){
        for(int j = 0; j < X_SQUARES; j++){
            boardStatus[i][j] = EMPTY;
        }
    }
}

char ** getBoardStatus() {
    return boardStatus;
}

void updateBoard(snake * s1, snake * s2, food * currentFood) {
    updateBoardFromSnake(s1);
    updateBoardFromSnake(s2);
    // if ( (boardStatus[currentFood->position.y][currentFood->position.x] != s1->playerReference) && (s2 == NULL || (boardStatus[currentFood->position.y][currentFood->position.x] != s2->playerReference) ) ) {

    // }
}

static void updateBoardFromSnake(snake * s) {
    if (s == NULL) {
        return;
    }
    for (int i = 0; i < s->length; i++) {
        boardStatus[s->body[i].y][s->body[i].x] = s->playerReference;
    }
}



void scoreStatus(snake * s1, snake * s2){
    if(players == 2){
        pointsTab(s1->points, s2->points);
    }else{
        pointsTab(s1->points, 0);
    }
}

int getPlayers(){
    return players;
}

void quitGame(){
    call_clear_screen();
    printf("\t\t\t\t\t Thanks for playing!\n");
    printf("\t\t\t\t\t Press any key to return to terminal...\n");
    getChar();
    call_clear_screen();
    return;
}

void lostGame(int player, snake * s1, snake * s2){ // cartel
    call_clear_screen();
    if(players == 2){
        printf("\t\t\t\t\t Player %d lost the game, Player %d WON!!\n", player, player%2 + 1);
        printf("\t\t\t\t\t Score Player 1: %d\n", s1->points);
        printf("\t\t\t\t\t Score Player 2: %d\n", s2->points);
        printf("\t\t\t\t\t Press any key to play again or ESC to quit game\n");
    }else{
        printf("\t\t\t\t\t You lost the game, try again!\n\n");
        printf("\t\t\t\t\t Score: %d\n", s1->points);
        printf("\t\t\t\t\t Press any key to play again or ESC to quit game\n");
    }

    char c = getChar();

    if(c == 27){
        exit = 1;
        quitGame();
    }

    snakeGame();
}

static void screen(){ // ymax = 768 xmax = 1024
    pointsTab(0, 0);

    for(int i = 0; i < X_SQUARES; i++){ // x
        for(int j = 1; j < Y_SQUARES; j++){ // y  skip first row because it is the menu
            if((j%2 && i%2) || (j%2 == 0 && i%2 == 0)){
                call_draw_square(boardTheme[2][0], PIXEL_POS(i), PIXEL_POS(j), 32);
            }else{
                call_draw_square(boardTheme[2][1], PIXEL_POS(i), PIXEL_POS(j), 32);
            }
        }
    }
}

static void pointsTab(int player1, int player2) {
    void call_c_init(MENU_X, MENU_Y, MENU_SCALE);
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