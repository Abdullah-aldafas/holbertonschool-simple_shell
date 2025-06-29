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
void remove_newline(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			break;
		}
		i++;
	}
}
int _strchr_slash(char *s)
{
	while (*s)
	{
		if (*s == '/')
			return (1);
		s++;
	}
	return (0);
}
int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
