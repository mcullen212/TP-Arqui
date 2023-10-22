#include <shell.h>

void shell(char * command) {

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

