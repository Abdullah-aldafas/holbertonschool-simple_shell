#include "shell.h"

/**
 * tokenize - Splits a line into tokens without using strtok or isspace
 * @line: The input string to split
 * @args: The array to store the tokens
 */
void tokenize(char *line, char **args)
{
	int i = 0;
	char *start = line;
	while (*start)
	{
		while (*start && _isspace(*start)) /* <-- بديل isspace */
			start++;
		if (*start == '\0')
			break;
		args[i++] = start;
		while (*start && !_isspace(*start))
			start++;
		if (*start)
		{
			*start = '\0';
			start++;
		}
	}
	args[i] = NULL;
}
