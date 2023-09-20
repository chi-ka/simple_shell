#include <stdio.h>
#include "main.h"
#include <math.h>

/**
 * _pow - converts string to int
 *
 * @a: int input
 *
 * @b: power input
 *
 * Return: int output
 */

int _pow(double a, double b)
{
	int i;

	i = a;
	while (b > 1)
	{
		a *= i;
		b--;
	}
	return (a);
}

/**
 * _atoi - converts string to int
 *
 * @s: input char
 *
 * Return: an int
 */

int _atoi(char *s)
{
	char *a;
	char *z;
	char c = '\0';
	int place;
	int count = 0;
	int number = 0;

	while (*s != '\0')
	{
		if ('0' <= *s && *s <= '9')
		{
			count++;
			if (count == 1)
			{
				a = s;
				z = s;
				if (*(s - 1) == '-')
				{
					c = '-';
				}
			}
			z++;
		}
		s++;
	}
	while (a < z)
	{
		place = _pow(10, (count - 1));
		number += ((*a - '0') * place);
		a++;
		count--;
	}
	if (c == '-')
	{
		number = -number;
	}
	return (number);
}
