#include <commands.h>

void man(){
    printf("Welcome to Wuevo\n");
    printf("NAME\n");
    printf("\t man - is an the manual to the system refernce\n\n");
    printf("DESCRIPTION\n");
    printf("\tThis manual is a project for Computer Architecture created by Agustine Alonso, Magdalena Cullen, and Tomas Becerra.\n\n");
    printf("PROGRAMS AVAILABLE FOR USER\n");
    printf("\t man - Access the manual.\n");
    printf("\t time - Retrieve the current time.\n");
    printf("\t snake - Play the Snake game, available for both single-player and two-player modes. Follow the command with the number \n");
    printf("\t\t of players you want to play with.\n");
    printf("\t registers - View the registers in use after pressing Ctrl + Alt.\n\n");
    printf("EXCEPTIONS\n");
    printf("\t inval - Indicates an invalid operation.\n");
    printf("\t div0 - Signals division by zero.\n");
}