#include <shell.h>
#include <stdint.h>
#include <libc.h>

#define EXCEPTION_COMMAND "Error: command not found"

static uint64_t x=0, y=0;  //Top left hand corner of screen

void shell(char *command) {
    int id = interpretCommand(command);
    char *flag;
    executeCommand(id, &flag);

    if(!flag){
        printf(EXCEPTION_COMMAND);
        return;
    }
}

int interpretCommand(char * command) {
    for (int i = 0; i < AMOUNT_OF_COMMANDS; i++) {
        if (strcmp(command, commands[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void executeCommand(int indexCommand, char * flag) {
    if (indexCommand == -1) {
        *flag = 0;
        return;
    }

    //commandsReferences[indexCommand]();
    *flag = 1;
}



