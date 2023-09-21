#include <stdio.h>
#include "main.h"

/**
 * findExecutable - main code
 * @command: the command
 * Return: string
 */

char *findExecutable(char *command)
{
	char *path, *token, *path_copy;

	if (access(command, X_OK) == 0)
	{
		return (strdup(command));
	}
	path = getenv("PATH");
	if (path == NULL)
	{
		perror("Failed to get PATH environment variable");
		exit(EXIT_FAILURE);
	}
	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char executable[MAX_CMD_LEN];

		snprintf(executable, sizeof(executable), "%s/%s", token, command);
		if (access(executable, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(executable));
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);

	return (NULL);
}

