#include <stdio.h>
#include "main.h"

/**
 * custom_getline - Read a line from standard input.
 *
 * Return: A pointer to the line read, or NULL on failure or EOF.
 */
char *custom_getline(void)
{
	char currentChar;
	char *line = NULL;
	int lineLength = 0;
	static int position, bytesRead;
	static char buffer[MAX_BUFFER_SIZE];

	while (1)
	{
		if (position == bytesRead)
		{
			char dollar_sign = '$', dollar_space = ' ';
			write(STDOUT_FILENO, &dollar_sign, 1);
			write(STDOUT_FILENO, &dollar_space, 1);
			bytesRead = read(STDIN_FILENO, buffer, MAX_BUFFER_SIZE);
			position = 0;

			if (bytesRead <= 0 && lineLength == 0)
			{
				return NULL;
			}
			else if (bytesRead <= 0)
			{
				break;
			}
		}

		currentChar = buffer[position++];

		if (currentChar == '\n')
		{
			break;
		}

		if (lineLength == 0)
		{
			line = (char *)malloc(2);
			if (!line)
			{
				perror("malloc failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *temp = (char *)realloc(line, lineLength + 2);
			if (!temp)
			{
				perror("realloc failed");
				free(line);
				exit(EXIT_FAILURE);
			}
			line = temp;
		}
		line[lineLength++] = currentChar;
		line[lineLength] = '\0';
	}

	return line;
}
