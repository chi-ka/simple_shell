#include <stdio.h>
#include "main.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: first string to compare
 *
 * @s2: Second string
 *
 * Return: an int value
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
		{
			break;
		}
		else
		{
			s1++;
			s2++;
		}
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
