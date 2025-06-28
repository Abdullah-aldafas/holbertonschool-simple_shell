#include "shell.h"

/**
 * split_line - Tokenizes a given string into words separated by spaces.
 *              This is a custom tokenizer that does not use strtok().
 *
 * @line: The input string to tokenize (e.g., "ls -l /tmp")
 *
 * Return: A NULL-terminated array of strings (tokens).
 */
char **split_line(char *line)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *start = line, *end;

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	while (*start != '\0')
	{
		/* Skip any spaces */
		while (*start == ' ')
			start++;

		if (*start == '\0')
			break;

		/* Find the end of the word */
		end = start;
		while (*end != ' ' && *end != '\0')
			end++;

		int length = end - start;

		/* Allocate memory for the token and copy it */
		tokens[i] = malloc(length + 1);
		if (!tokens[i])
		{
			perror("allocation error");
			exit(EXIT_FAILURE);
		}

		strncpy(tokens[i], start, length);
		tokens[i][length] = '\0';
		i++;

		/* Move to the next word */
		start = end;

		/* Resize the token array if needed */
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("reallocation error");
				exit(EXIT_FAILURE);
			}
		}
	}

	tokens[i] = NULL;
	return tokens;
}
