#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#define MAX_CMD_LEN 128

extern char **environ;

void executeCommand(char *cmd, int *commandStatus);
void envCommand(void);
void handleError(char *cmd);
char *findExecutable(char *command);
int parseCommand(char *cmd, char *argv[], int *argc);

#endif /* MAIN_H */
