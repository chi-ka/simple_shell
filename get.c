#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * check_and_refill_buffer - Check and refill the buffer if needed.
 *
 * @info: Pointer to the BufferInfo struct.
 *
 * Return: A pointer to the next character in the buffer or NULL on EOF/error.
 */
char *check_and_refill_buffer(BufferInfo *info)
{
	if (info->position == info->bytesRead)
	{
		char dollar_sign = '$', dollar_space = ' ';

		write(STDOUT_FILENO, &dollar_sign, 1);
		write(STDOUT_FILENO, &dollar_space, 1);
		info->bytesRead = read(STDIN_FILENO, info->buffer, MAX_BUFFER_SIZE);
		info->position = 0;

		if (info->bytesRead <= 0)
		{
			return (NULL);
		}
	}

	return (&(info->buffer[info->position]));
}

/**
 * read_line - Read a line from the input buffer.
 *
 * @info: Pointer to the BufferInfo struct.
 *
 * Return: A dynamically allocated string containing the line.
 */
char *read_line(BufferInfo *info)
{
	char *line = NULL;
	int lineLength = 0;
	char currentChar;

	while (1)
	{
		char *checkResult = check_and_refill_buffer(info);

		currentChar = *checkResult;
		info->position++;
		if (currentChar == '\n' || checkResult == NULL)
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

	return (line);
}

/**
 * custom_getline - Read a line from the standard input.
 *
 * Return: A dynamically allocated string containing the line.
 */
char *custom_getline(void)
{
	BufferInfo bufferInfo;

	bufferInfo.position = 0;
	bufferInfo.bytesRead = 0;

	return (read_line(&bufferInfo));
}

