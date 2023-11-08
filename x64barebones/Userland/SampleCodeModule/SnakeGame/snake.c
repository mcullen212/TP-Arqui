#include <snake.h>

// Game -----------------------------------------------------------------------------
static void pointsTab(int player1, int player2);
static char inputPlayer1(snake * s);
static char inputPlayer2(snake * s1, snake * s2);
static int snakeMenu();
static void gameStarter();

// Board ----------------------------------------------------------------------------
static void updateBoardFromSnake(snake * s);
static void updateBoardFromFood();
static void resetSquare(int xPos, int yPos);

static char boardStatus[Y_SQUARES][X_SQUARES];
static void themeColor();

static int boardThemes[][2] = {
    {PALE_BLUE, PALE_BLUE_LIGHTER},
    {PALE_YELLOW, PALE_YELLOW_LIGHTER},
    {PALE_GREEN, PALE_GREEN_LIGHTER}
};

static uint32_t dark = 0x000000;
static uint32_t light = 0xFFFFFF;

// snake -----------------------------------------------------------------------------
static char collision(snake * s);
static char ateFood(snake * s);
static void updateBody(snake * s);
static void updateBodyAfterMeal(snake * s);
static void themeSnake(snake * s1, snake * s2);

// Food -----------------------------------------------------------------------------

static food * currentFood;

static int foodType[] = {APPLE, STRAWBERRY, WATERMELON, CHERRY};


// Players ------------------------------------------------------------------------
static int players = 1;
static char exit = 0;
static int topScore = 0;

static void topPointsInGame(snake * s1, snake * s2);

// Game -----------------------------------------------------------------------------
void snakeNewGame(){
    topScore = 0; // reset for each new game
    snakeGame();
    quitGame();
    return;
}

void snakeGame(){
    exit = 0;
    call_clear_screen();
    players = snakeMenu();
    themeColor();

    createBoard();

    snake snakeP1, snakeP2;

    createSnake(&snakeP1, SNAKE_BLUE, 1);

    if(players == 2){
        createSnake(&snakeP2, SNAKE_YELLOW, 2);
    }

    themeSnake(&snakeP1, &snakeP2);
    call_clear_screen();

    gameStarter();
    pointsTab(0, 0);

    char p1=0, p2=0;
    createFood();
    updateBoardFromFood();

    printBoard(&snakeP1,&snakeP2);
    printFood();
    call_sleep(100);

    while(exit != 1){
        if(players == 1){
            p1 = inputPlayer1(&snakeP1);
            scoreStatus(&snakeP1, NULL); // print current score of the game
        } else {
            p2 = inputPlayer2(&snakeP1, &snakeP2);
            scoreStatus(&snakeP1, &snakeP2); // print current score of the game
        }
        
        updateBoard(&snakeP1, &snakeP2);
        printBoard(&snakeP1, &snakeP2);     
        call_sleep(100);

        if(p1 || p2){
            if(players == 2){
                lostGame(p2, &snakeP1, &snakeP2);
            }else{
                lostGame(p1, &snakeP1, &snakeP2);
            }
        }
    }
}

static int snakeMenu() {
    printf("Welcome to Snake Game!\nSelect amount of players: (1 or 2)");
    char c;
    do {
        c = getChar();
    } while ( c != '1' && c != '2' );
    return c - '0';
}

static void themeColor(){
    printf("\n\n Now please select theme:\n 1. Blue\n 2. Yellow\n 3. Green\n");
    char c;
    do {
        c = getChar();
    } while ( c != '1' && c != '2' && c != '3');
    dark = boardThemes[c - '1'][0];
    light = boardThemes[c - '1'][1];
    if(c == '1'){
        printf("\nTheme: Blue\n");
    } else if(c == '2'){
        printf("\nTheme: Yellow\n");
    } else {
        printf("\nTheme: Green\n");
    }
}

static void themeSnake(snake * s1, snake * s2){
    char c, t;
    if(players == 1){
        printf("\n\n Select color for snake:\n");
        printf(" 1. Blue\n 2. Cyan\n 3. Magenta\n 4. Yellow\n");
        do {
            c = getChar();
        } while ( c != '1' && c != '2' && c != '3' && c != '4');
    } else{
        printf("Select color for player 1:\n \n 1. Blue\n 2. Cyan\n");
        do {
            c = getChar();
        } while ( c != '1' && c != '2');

        printf("Select color for player 2:\n \n 1. Magenta\n 2. Yellow\n");
        do {
            t = getChar();
        } while ( t != '1' && t != '2');
    }
    
    switch(c){
        case '1':
            s1->color = SNAKE_BLUE;
            printf("\nPlayer 1: color blue\n");
            break;
        case '2':
            s1->color = SNAKE_CYAN;
            printf("\nPlayer 1: color cyan\n");
            break;
        case '3':
            s1->color = SNAKE_MAGENTA;
            printf("\nPlayer 1: color magenta\n");
            break;
        case '4':
            printf("\nPlayer 1: color yellow\n");
            s1->color = SNAKE_YELLOW;
        break;
    }

    switch(t){
        case '1':
            s2->color = SNAKE_MAGENTA;
            printf("\nPlayer 2: color magenta\n");
            break;
        case '2':
            printf("\nPlayer 2: color yellow\n");
            s2->color = SNAKE_YELLOW;
    }
    call_sleep(2000);

}

static void pointsTab(int player1, int player2) {
    call_c_init(MENU, MENU_HEIGHT/4, MENU_SCALE);
    printf("ESC to quit game \t\t");
    printf("turn off CAPS-LOCK \t\t");

    printf("\t Points player 1:  %d \t", player1); // 624 

    if(players == 2){
        printf("\t Points player 2:  %d \t", player2); // 872
    }
}

void scoreStatus(snake * s1, snake * s2){
    if(players == 2){
        call_c_init(MENU_PLAYER_1, MENU_HEIGHT/4, MENU_SCALE);
        call_delete_char(); // delete last score
        call_delete_char();
        printf("%d", s1->points);
        call_c_init(MENU_PLAYER_2, MENU_HEIGHT/4, MENU_SCALE);
        call_delete_char(); // delete last score
        call_delete_char();
        printf("%d", s2->points);
        return;
    }
    
    call_c_init(MENU_PLAYER_1, MENU_HEIGHT/4, MENU_SCALE);
    call_delete_char(); // delete last score
    call_delete_char();
    printf("%d", s1->points);
    return;
}

static void topPointsInGame(snake * s1, snake * s2){
    if(players == 2){
        if(topScore < s1->points){
            topScore = s1->points;
        }
        if(topScore < s2->points){
            topScore = s2->points;
        }
    }else{
        if(topScore < s1->points){
            topScore = s1->points;
        }
    }
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
    }else{
        printf("\t\t\t\t\t You lost the game, try again!\n\n");
        printf("\t\t\t\t\t Score: %d \n", s1->points);
    }

    topPointsInGame(s1, s2);
    printf("\n\t\t\t\t\t Top score: %d \n\n", topScore);
    printf("\t\t\t\t\t Press any key to play again or ESC to quit game\n");

    char c = getChar();

    if(c == 27){
        exit = 1;
        return;
    }

    snakeGame();
    return;
}

static void gameStarter(){
    call_c_init(80, Y_MAX/2, 2);
    printf("\t\t\t\t\t Game start in: ");
    for(int i=3; i >= 0; i--){
        printf("%d", i);
        call_sleep(1000);
        call_delete_char();
    }
    for(int i=0; i<15; i++){
        call_delete_char();
    }
    pointsTab(0, 0);
    return;
}

// Board ----------------------------------------------------------------------------
void createBoard(){
    for(int i = 0; i < Y_SQUARES; i++){
        for(int j = 0; j < X_SQUARES; j++){
            boardStatus[i][j] = EMPTY;
        }
    }
    return;
}

void printBoard(snake * s1, snake * s2) {
    for (int i = 0; i < Y_SQUARES; i++) {
        for (int j = 0; j < X_SQUARES; j++) {
            if(boardStatus[i][j] == SNAKE_PLAYER_1){
                    call_draw_square(s1->color, PIXEL_POS_X(j), PIXEL_POS_Y(i), SQUARE_SIZE);
            }
            else if(boardStatus[i][j] == SNAKE_PLAYER_2){
                    call_draw_square(s2->color, PIXEL_POS_X(j), PIXEL_POS_Y(i), SQUARE_SIZE);
            }
            else if(boardStatus[i][j] == FOOD){
                printFood();
            }else{
                resetSquare(j, i);
            }
        }
    }
}

static void resetSquare(int xPos, int yPos) {
    if( (xPos % 2 && yPos % 2) || (xPos % 2 == 0 && yPos % 2 == 0)){
        call_draw_square(dark, PIXEL_POS_X(xPos), PIXEL_POS_Y(yPos), SQUARE_SIZE);
    } else {
        call_draw_square(light, PIXEL_POS_X(xPos), PIXEL_POS_Y(yPos), SQUARE_SIZE);
    }
}

void updateBoard(snake * s1, snake * s2) {
    updateBoardFromSnake(s1);
    updateBoardFromSnake(s2);
}

static void updateBoardFromSnake(snake * s) {
    if (s == NULL) {
        return;
    }
    for (int i = 0; i < s->length; i++) {
        boardStatus[s->body[i].y][s->body[i].x] = s->playerReference;
    }
}

static void updateBoardFromFood() {
    boardStatus[currentFood->position.y][currentFood->position.x] = FOOD;
}

// Game control ----------------------------------------------------------------------
static char inputPlayer1(snake * s){ // que mov tiene la serpiente
    int readBytes;
    char c = readChar(&readBytes);
    char lost = 0;
    if(readBytes){
       switch(c){  // New input
            case 27: // Quit game (ESC)
                exit = 1;
                break;
            case 'w': // Move up
                if(s->lastMove != DOWN){
                    lost = moveSnake(s, UP);
                }
                break;
            case 's': // Move down
                if(s->lastMove != UP){
                    lost = moveSnake(s, DOWN);
                }
                break;
            case 'a': // Move left
                if(s->lastMove != RIGHT){
                    lost = moveSnake(s, LEFT);
                }
                break;
            case 'd': // Move right
                if(s->lastMove != LEFT){
                    lost = moveSnake(s, RIGHT);
                }
            default:
                lost = moveSnake(s, s->lastMove);
                break;
        }
    } else { // No new input, continues with the same movement
        lost = moveSnake(s, s->lastMove);
    }
    return lost;
}

static char inputPlayer2(snake * s1, snake * s2){
    int readBytes;
    char c = readChar(&readBytes);
    char lost = 0, aux = 0;
    if(readBytes) {
        switch(c) {
            case 27: // Quit game (ESC)
                exit = 1;
                break;
            case 'w': // Move up
                if(s1->lastMove != DOWN){
                    lost = moveSnake(s1, UP);
                    aux = moveSnake(s2, s2->lastMove);
                    lost = (aux > lost)? aux : lost;
                }
                break;
            case 's': // Move down
                if(s1->lastMove != UP){
                    lost = moveSnake(s1, DOWN);
                    aux = moveSnake(s2, s2->lastMove);
                    lost = (aux > lost)? aux : lost;
                }
                break;
            case 'a': // Move left
                if(s1->lastMove != RIGHT && s1->lastMove != LEFT){
                    lost = moveSnake(s1, LEFT);
                    aux = moveSnake(s2, s2->lastMove);
                    lost = (aux > lost)? aux : lost;
                }
                break;
            case 'd': // Move right
                if(s1->lastMove != LEFT){
                    lost = moveSnake(s1, RIGHT);
                    aux = moveSnake(s2, s2->lastMove);
                    lost = (aux > lost)? aux : lost;
                }
                break;
            case 'i': // Move up
                if(s2->lastMove != DOWN){
                    lost = moveSnake(s2, UP)? 2 : 0;
                    aux = moveSnake(s1, s1->lastMove);
                    lost = (aux > lost)? aux : lost;
                }
                break;
            case 'k': // Move down
                if(s2->lastMove != UP && s2->lastMove != DOWN){
                    lost = moveSnake(s2, DOWN)? 2 : 0;
                    aux = moveSnake(s1, s1->lastMove);
                    lost = (aux > lost)? aux : lost;
                }
                break;
            case 'j': //Move left
                if(s2->lastMove != RIGHT){
                    lost = moveSnake(s2, LEFT)? 2 : 0;
                    aux = moveSnake(s1, s1->lastMove);
                    lost = (aux > lost)? aux : lost;
                }
                break;
            case 'l': // Move Right 
                if(s2->lastMove != LEFT){
                    lost = moveSnake(s2, RIGHT)? 2 : 0;
                    aux = moveSnake(s1, s1->lastMove);
                    lost = (aux > lost)? aux : lost;
                }
                break;
            default:
                aux = moveSnake(s1, s1->lastMove);
                lost = moveSnake(s2, s2->lastMove);
                lost = (aux > lost)? aux : lost;
                break;
        }
    }else {
        aux = moveSnake(s1, s1->lastMove);
        lost = moveSnake(s2, s2->lastMove);
        lost = (aux > lost)? aux : lost;
    }
    return lost;
}

// Snake -----------------------------------------------------------------------------

void createSnake(snake * s, uint32_t color, int player) {
    // Player 1 initialization
    if(player == 1){
        s->playerReference = SNAKE_PLAYER_1;
        s->color = color;
        s->head.x = MIN_SNAKE_LENGTH - 1;
        s->head.y = Y_SQUARES / 2 + 1;
        for(int i = 0; i <= s->head.x; i++){ // Tail (x,y) is the first element of "body" array.
            s->body[i].x = i;
            s->body[i].y = s->head.y;
            boardStatus[s->head.y][i] = s->playerReference;
        }
        s->length = MIN_SNAKE_LENGTH;
        s->lastMove = RIGHT;
        s->points = 0;
        boardStatus[s->head.y][s->head.x] = s->playerReference;
        return;
    }
    // Player 2 initialization
    s->playerReference = SNAKE_PLAYER_2;
    s->color = color;
    s->head.x = X_SQUARES-MIN_SNAKE_LENGTH;
    s->head.y = Y_SQUARES / 2 - 1;
    for(int i = X_SQUARES-1, j=0; i >= s->head.x && j < MIN_SNAKE_LENGTH; j++, i--){ // Tail (x,y) is the first element of "body" array.
        s->body[j].x = i;
        s->body[j].y = s->head.y;
        boardStatus[s->head.y][i] = s->playerReference;
    }
    s->length = MIN_SNAKE_LENGTH;
    s->lastMove = LEFT;
    s->points = 0;
    boardStatus[s->head.y][s->head.x] = s->playerReference;
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
        case LEFT: // Left <<--
            s->head.x -= 1; // Head update
            if(collision(s)){
                return 1;
            }
            s->lastMove = LEFT;
            break;
        case RIGHT: // Right -->>
            s->head.x += 1;
            if(collision(s)){
                return 1;
            }
            s->lastMove = RIGHT;
            break;
        default:
            break;
    }
    if (ateFood(s)) {
        s->points++; // Increase points
        updateBodyAfterMeal(s);
        updateBoardFromFood(currentFood);
        return 0;
    }
    updateBody(s);
    return 0;
}

static char collision(snake * s){
    if(boardStatus[s->head.y][s->head.x] != EMPTY && boardStatus[s->head.y][s->head.x] != FOOD ){ // Collision with its snake
        call_beep(500);
        call_beep(300);
        call_beep(100);
        return 1;
    }
    else if(s->head.x < 0 || s->head.x > X_SQUARES - 1 || s->head.y < 0 || s->head.y > Y_SQUARES - 1){ // Collision with the wall
        call_beep(2000);
        call_beep(1000);
        call_beep(500);
        return 1;
    }
    return 0;
}

static char ateFood(snake * s){
    if (s->head.x == currentFood->position.x && s->head.y == currentFood->position.y) {
        call_beep(100);
        createFood(); // generates a new food
        return 1;
    }
    return 0;
}

static void updateBody(snake * s) {
    int i;
    boardStatus[s->body[0].y][s->body[0].x] = EMPTY; // Reset square at tail position
    for (i = 1; i < s->length; i++) {
        s->body[i - 1] = s->body[i];
    }
    s->body[i - 1] = s->head;
}

static void updateBodyAfterMeal(snake * s) {
    s->length++;
    s->body[s->length - 1] = s->head;
}

// Food -----------------------------------------------------------------------------
void createFood(){
    int xCoord, yCoord;
    do {
        xCoord = randNbr(0, X_SQUARES - 1);
        yCoord = randNbr(1,Y_SQUARES - 1);
    } while (boardStatus[yCoord][xCoord] != EMPTY);

    currentFood->position.x = xCoord;
    currentFood->position.y = yCoord;
    currentFood->color = foodType[randNbr(0,FOOD_TYPES - 1)];
}

void printFood(){
    call_draw_square(currentFood->color, PIXEL_POS_X(currentFood->position.x), PIXEL_POS_Y(currentFood->position.y), SQUARE_SIZE);
}