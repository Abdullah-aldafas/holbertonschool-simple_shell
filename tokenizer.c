#include "shell.h"

/**
 * count_letters - Count letters in the current word (token)
 * @start: Pointer to current position in string
 *
 * Return: Length of word
 */
int count_letters(char *start)
{
	int len = 0;

	while (start[len] && start[len] != ' ')
		len++;

	return (len);
}

/**
 * add_token - Allocates and copies a token from the input
 * @tokens: Array of token pointers
 * @start: Pointer to beginning of token
 * @len: Length of the token
 * @index: Current index to store token in array
 */
void add_token(char **tokens, char *start, int len, int index)
{
	tokens[index] = malloc(len + 1);
	if (!tokens[index])
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	strncpy(tokens[index], start, len);
	tokens[index][len] = '\0';
}

/**
 * split_line - Splits a line into tokens (no strtok used)
 * @line: The input line from user
 *
 * Return: NULL-terminated array of tokens
 */
char **split_line(char *line)
{
	int bufsize = 64, i = 0, len;
	char **tokens;
	char *start = line;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (*start)
	{
		while (*start == ' ')
			start++;

		if (*start == '\0')
			break;

		len = count_letters(start);
		add_token(tokens, start, len, i);
		i++;

		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		start += len;
	}

	tokens[i] = NULL;
	return (tokens);
}
