#include <stdio.h>
#include "main.h"

/**
 * strtok_custom - Custom implementation of strtok.
 * @str: The string to tokenize (or NULL to continue tokenizing).
 * @delimiters: A string containing delimiter characters.
 *
 * Return: A pointer to the next token in the string or NULL if no more tokens.
 */

char *strtok_custom(char *str, const char *delimiters)
{
	static char *nextToken;
	char *tokenStart;
	char *tokenEnd;

	nextToken = NULL;
	if (str != NULL)
	{
		nextToken = str;
	}
	else if (nextToken == NULL)
	{
		return (NULL);
	}

	tokenStart = nextToken;
	tokenEnd = strpbrk(tokenStart, delimiters);
	if (tokenEnd != NULL)
	{
		*tokenEnd = '\0';
		nextToken = tokenEnd + 1;
	}
	else
	{
		nextToken = NULL;
	}

	return (tokenStart);
}
