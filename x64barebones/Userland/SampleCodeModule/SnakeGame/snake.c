#include <snake.h>

// Game -----------------------------------------------------------------------------
static void screen();
static void pointsTab(int player1, int player2);
static char inputPlayer1(snake * s);
static char inputPlayer2(snake * s1, snake * s2);
static int snakeMenu();

// Board ----------------------------------------------------------------------------
static void updateBoardFromSnake(snake * s);
static void resetSquare(int xPos, int yPos);

static char boardStatus[Y_SQUARES][X_SQUARES];

// snake -----------------------------------------------------------------------------
static char collision(snake * s);
static char ateFood(snake * s);
static void updateBody(snake * s);
static void updateBodyAfterMeal(snake * s);

// Food -----------------------------------------------------------------------------

static food * currentFood;

static int foodType[] = {APPLE, BANANA, STRAWBERRY, WATERMELON, CHERRY, PINEAPPLE};



static int players = 1;
static char exit = 0;

// static int boardTheme[3][2] = {
//     {PALE_BLUE, PALE_BLUE_LIGHTER},
//     {PALE_YELLOW, PALE_YELLOW_LIGHTER},
//     {PALE_GREEN, PALE_GREEN_LIGHTER}
// };

// Game -----------------------------------------------------------------------------
void snakeGame(){
    exit = 0;
    call_clear_screen();
    players = snakeMenu();
    call_clear_screen();
    pointsTab(0, 0);
    //screen();
    createBoard();

    snake snakeP1, snakeP2;

    createSnake(&snakeP1, SNAKE_BLUE, 1);

    if(players == 2){
        createSnake(&snakeP2, SNAKE_YELLOW, 2);
    }

    char p1, p2;
    createFood();

    printBoard(&snakeP1,&snakeP2);
    call_sleep(4000);
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

        if(p1 || p2){
            if(players == 2){
                lostGame(p2, &snakeP1, &snakeP2);
                return;
            }
            lostGame(p1, &snakeP1, &snakeP2);
        }
        
        call_sleep(500);
    }
    quitGame();
}

static int snakeMenu() {
    printf("Welcome to Snake Game!\nSelect amount of players: (1 or 2)");
    char c;
    do {
        c = getChar();
    } while ( c != '1' && c != '2' );
    //scanf("%d", &players);
    return c - '0';
}

static void pointsTab(int player1, int player2) {
    call_c_init(MENU_X, MENU_Y, MENU_SCALE);
    printf("\tESC to quit game \t\t");
    printf("turn off CAPS-LOCK \t\t");
    if(players == 2){
        printf("\tPoints player 1: %d \t", player1);
        printf("\t Points player 2: %d \t", player2);
    }else{
        printf("\tPoints player: %d \t", player1);
    }
}

void scoreStatus(snake * s1, snake * s2){
    if(players == 2){
        pointsTab(s1->points, s2->points);
    }else{
        pointsTab(s1->points, 0);
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
        printf("\t\t\t\t\t Press any key to play again or ESC to quit game\n");
    }else{
        printf("\t\t\t\t\t You lost the game, try again!\n\n");
        printf("\t\t\t\t\t Score: %d\n", s1->points);
        printf("\t\t\t\t\t Press any key to play again or ESC to quit game\n");
    }

    char c = getChar();

    if(c == 27){
        exit = 1;
        return;
    }

    snakeGame();
}

// Board ----------------------------------------------------------------------------
void createBoard(){
    for(int i = 0; i < Y_SQUARES; i++){
        for(int j = 0; j < X_SQUARES; j++){
            boardStatus[i][j] = EMPTY;
        }
    }
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
            else if(boardStatus[i][j] ==FOOD){
                    call_draw_circle(currentFood->color, PIXEL_POS_X(j), PIXEL_POS_Y(i), SQUARE_SIZE);
            }
            else{
                resetSquare(j, i);
            }
        }
    }
}

static void resetSquare(int xPos, int yPos) {
    if( (xPos % 2 && yPos % 2) || (xPos % 2 == 0 && yPos % 2 == 0)){
        call_draw_square(PALE_GREEN, PIXEL_POS_X(xPos), PIXEL_POS_Y(yPos), SQUARE_SIZE);
    } else {
        call_draw_square(PALE_GREEN_LIGHTER, PIXEL_POS_X(xPos), PIXEL_POS_Y(yPos), SQUARE_SIZE);
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

void updateBoardFromFood(food * currentFood) {
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
                lost = moveSnake(s, s->lastMove);
                break;
        }
    } else { // No new input, continues with the same movement
        lost = moveSnake(s, s->lastMove);
    }
    return lost;
}

static char inputPlayer2(snake * s1, snake * s2){
    int readBytes, aux;
    char c = readChar(&readBytes);
    char lost = 0;
    if(readBytes) {
        switch(c) {
            case 27: // Quit game (ESC)
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
    for(int i = X_SQUARES-1; i >= s->head.x; i--){ // Tail (x,y) is the first element of "body" array.
        s->body[i].x = i;
        s->body[i].y = s->head.y;
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
        updateBoardFromFood(currentFood);
        return 0;
    }
    updateBody(s);
    return 0;
}

static char collision(snake * s){
    if(boardStatus[s->head.y][s->head.x] != EMPTY && boardStatus[s->head.y][s->head.x] != FOOD ){ // Collision with its snake
        return 1;
    }
    else if(s->head.x < 0 || s->head.x > X_SQUARES || s->head.y < 1 || s->head.y > Y_SQUARES){ // Collision with the wall
        return 1;
    }
    return 0;
}

static char ateFood(snake * s){
    if (s->head.x == currentFood->position.x && s->head.y == currentFood->position.y) {
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