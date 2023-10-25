#ifndef SHELL_H
#define SHELL_H

#include "externalLibraries.h"

#define AMOUNT_OF_COMMANDS 4

// Shell manager
void shell(char * command);

// Checks if the command is valid
int interpretCommand(char * command);

// Executes the command
void executeCommand(int indexCommand, char * flag);

char * commands = {"man", "time", "registers", "snake"};

//void (* commandsReferences[])() = {man, time, registers, snake};

#endif