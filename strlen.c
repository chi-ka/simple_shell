#include <stdio.h>
#include "main.h"

/**
 * _strlen - counts lenght of a string
 *
 * @s: string input
 *
 * Return: an integer count
 */

int _strlen(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen(s + 1));
}
