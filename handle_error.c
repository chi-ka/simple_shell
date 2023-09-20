#include <stdio.h>
#include "main.h"

/**
 * handle_exit - Handles the "exit" command.
 * @input: The input string containing the command.
 * @should_exit: A pointer to a flag.
 * @exit_status: A pointer to the exit status of the program.
 */
void handle_exit(char *input, int *should_exit, int *exit_status)
{
	char *token = strtok_custom(input, " \t\n\r");

	token = strtok_custom(NULL, " \t\n\r");

	if (token == NULL)
	{
		*should_exit = 1;
		*exit_status = 0;
	}
	else
	{
		*exit_status = _atoi(token);
		*should_exit = 1;
	}
}

