#include <stdio.h>
#include "main.h"

/**
 * _strncmp - compares two strings
 *
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of characters to compare
 *
 * Return: an int value
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
