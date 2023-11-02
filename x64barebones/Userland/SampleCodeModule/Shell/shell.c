#include <shell.h>
#include <stdint.h>
#include <libc.h>
#include <commands.h>

char * commands[6] = {"man", "time", "registers", "snake", "div0", "invalid operation"};

void (* commandsReferences[])() = {man, time, registers, /*snake,*/ div0, invalidop};

void shell(char *command) {
    int id = interpretCommand(command);
    char flag = 0;
    executeCommand(id, &flag);

    if(flag == 0) {
        uint32_t num;
        call_write((uint8_t *)"Error: command not found", &num);
    }
}

int interpretCommand(char * command) {
    int index = -1;
    for (int i = 0; i < AMOUNT_OF_COMMANDS; i++) {
        if (strcmp(command, commands[i]) == 0) {
            index = i;
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



