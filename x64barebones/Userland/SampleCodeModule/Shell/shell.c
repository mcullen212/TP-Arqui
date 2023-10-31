#include <shell.h>
#include <stdint.h>
#include <libc.h>

#define EXCEPTION_COMMAND "Error: command not found"

void shell(char *command) {
    int cantArguments;
    char ** arguments = substrings(command, ' ', &cantArguments);
    int id = interpretCommand(arguments[0]);
    char * flag;
    *flag = 0;
    executeCommand(id, arguments+1,flag);

    if(!flag) {
        //printf(EXCEPTION_COMMAND);
        return;
    }
}

int interpretCommand(char * command) {
    int index = -1;
    for (int i = 0; i < AMOUNT_OF_COMMANDS; i++) {
        // if (strcmp(command, commands[i]) == 0) {
        //     index = i;
        // }
    }
    return index;
}

void executeCommand(int indexCommand, char ** arguments, char * flag) {
    if (indexCommand == -1 ) {
        *flag = 0;
        return;
    }//cantArg logic missing

    //commandsReferences[indexCommand]();
    *flag = 1;
}



