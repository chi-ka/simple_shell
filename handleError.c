#include <stdio.h>
#include "main.h"

/**
 * handleError -  Handle and report errors.
 *
 * @cmd: The command that encountered an error.
 */
void handleError(char *cmd)
{
	char error_msg[128];

	strcpy(error_msg, cmd);
	strcat(error_msg, ": ");
	strcat(error_msg, strerror(errno));
	strcat(error_msg, "\n");
	write(STDERR_FILENO, error_msg, strlen(error_msg));
}
