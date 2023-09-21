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


void executeCommand(char *cmd);
void handleError(char *cmd);
char* findExecutable(char *command);

#endif /* MAIN_H */
