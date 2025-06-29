#include "shell.h"
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
int _is_number(char *s)
{
	int i = 0;
	if (s[0] == '-') // دعم الأرقام السالبة
		i++;
	for (; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}
int _atoi(char *s)
{
	int result = 0, sign = 1, i = 0;
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[0] == '+')
	{
		i++;
	}
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
