#include <stdio.h>
#include "main.h"

/**
 * split_input - Split input string into an array of arguments.
 * @input: The input string to split.
 * @delimiters: The seperators used.
 *
 * Return: An array of arguments (strings).
 */

char **split_input(char *input, const char *delimiters)
{
	char *token;
	char **args = NULL;
	int i = 0;

	args = malloc(BUFFER_SIZE * sizeof(char *));
	if (!args)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok_custom(input, delimiters);

	while (token != NULL)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			perror("strdup failed");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok_custom(NULL, delimiters);
	}
	args[i] = NULL;

	return (args);
}
