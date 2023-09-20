#include <stdio.h>
#include "main.h"

/**
 * print_env - Print the current environment.
 * @env: The environment variables.
 */
void print_env(char **env)
{
	int i = 0;
	int fd = STDOUT_FILENO;

	while (env[i] != NULL)
	{
		write(fd, env[i], _strlen(env[i]));
		write(fd, "\n", 1);
		i++;
	}
}
