#include <stdio.h>
#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring that consists of only
 * characters found in another string.
 * @s: The string to search.
 * @accept: The string containing characters to match.
 *
 * Return: The number of bytes in the initial segment of s which consist
 * only of bytes NOT in accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	while (*s)
	{
		int found = 0;
		char *a;

		for (a = accept; *a; a++)
		{
			if (*s == *a)
			{
				found = 1;
				break;
			}
		}

		if (found)
		{
			break;
		}

		count++;
		s++;
	}

	return (count);
}

