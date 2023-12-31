#ifndef SHELL_H
#define SHELL_H

#define AMOUNT_OF_COMMANDS 11

// Shell manager
void shell(char * command);

// Checks if the command is valid
int interpretCommand(char * command);

// Executes the command
void executeCommand(int indexCommand, char * flag);

#endif
