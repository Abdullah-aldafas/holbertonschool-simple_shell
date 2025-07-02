#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: Difference between first unmatched characters
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _is_number - Checks if a string is a valid number
 * @s: Input string
 * Return: 1 if number, 0 otherwise
 */
int _is_number(char *s)
{
	int i = 0;

	if (s[0] == '-' || s[0] == '+')
		i++;
	for (; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (0);
	return (1);
}

/**
 * _atoi - Converts a string to integer
 * @s: Input string
 * Return: Converted integer
 */
int _atoi(char *s)
{
	int result = 0, sign = 1, i = 0;

	if (s[0] == '-')
		sign = -1, i++;
	else if (s[0] == '+')
		i++;

	while (s[i])
		result = result * 10 + (s[i++] - '0');

	return (result * sign);
}
