#include <shell.h>
#include <stdint.h>
#include <libc.h>
#include <commands.h>

char * commands[AMOUNT_OF_COMMANDS] = {"man", "time", "registers", "snake", "div0", "invalid op", "clear", "zoom in", "zoom out", "set theme"};

void (* commandsReferences[])() = {man, time, registers, snakeGame, div0, invalidOp, clear, zoomIn, zoomOut, theme};

void shell(char *command) {
    if(*command == 0){
        return;
    }
    int id = interpretCommand(command);
    char flag = 0;
    executeCommand(id, &flag);

    if(flag == 0) {
        printf("Error: command not found\n");
    }
}

int interpretCommand(char * command) {
    int index = -1;
    for (int i = 0; i < AMOUNT_OF_COMMANDS; i++) {
        if (strcmp(command, commands[i]) == 0) {
            return i;
        }
    }
    return index;
}

void executeCommand(int indexCommand, char * flag) {
    if (indexCommand == -1 ) {
        *flag = 0;
        return;
    }
    commandsReferences[indexCommand]();
    *flag = 1;
}



