#include <commands.h>

void man(){
    printf("Welcome to MAT\n");
    printf("NAME\n");
    printf("\t man - the manual to the system reference\n\n");
    printf("DESCRIPTION\n");
    printf("\t This is an assignment for a Computer Architecture Course at ITBA.\n");
    printf("\t Created by Agustin Alonso, Magdalena Cullen, and Tomas Becerra.\n\n");
    printf("PROGRAMS AVAILABLE FOR USER\n");
    printf("\t -- Do not include space after command. --\n");
    printf("\t man - Access the manual.\n");
    printf("\t time - Retrieve the current time.\n");
    printf("\t snake - Play the Snake game, available for both single-player and two-player modes. Follow the command with the number \n");
    printf("\t\t of players you want to play with.\n");
    printf("\t clear - Clear the screen.\n");
    printf("\t zoom in - Increase text size. Clears screen after change.\n");
    printf("\t zoom out - Decrease text size. Clears screen after change.\n");
    printf("\t registers - View the registers in use after pressing Shift + Alt.\n");
    printf("\t set theme - Choose terminal theme. Clears screen after change.\n");
    printf("\t Esto es Boca - BOCA.\n\n");
    printf("EXCEPTIONS\n");
    printf("\t inval op - Indicates an invalid operation.\n");
    printf("\t div0 - Signals division by zero.\n");
}
