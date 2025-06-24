#include "shell.h"
/**
 * main - Entry point for the shell program
 *
 * This function displays a prompt, waits for user input,
 * reads a line from standard input, tokenizes the input,
 * and executes the command.
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[64];

	while (1)
	{
		printf("$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			perror("getline");
			free(line);
			return (1);
		}
		line[strcspn(line, "\n")] = '\0';

		tokenize(line, args);
		if (args[0] == NULL)
			continue;
		execute_command(args);
	}
	free(line);
	return (0);
}
