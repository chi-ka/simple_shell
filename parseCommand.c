#include "main.h"

/**
 * parseCommand - Parse the input command and populate the argument array.
 *
 * @cmd: The input command string to be parsed.
 * @argv: An array of character pointers.
 * @argc: A pointer to an integer.
 *
 * Return: The total number of arguments parsed.
 */

int parseCommand(char *cmd, char *argv[], int *argc)
{
	char *token = strtok(cmd, " ");
	*argc = 0;

	while (token != NULL)
	{
		argv[(*argc)++] = token;
		token = strtok(NULL, " ");
	}

	argv[*argc] = NULL;

	return (*argc);
}
