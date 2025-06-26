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
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(0);
		}
		line[strcspn(line, "\n")] = '\0';

		tokenize(line, args);
		if (args[0] == NULL)
			continue;

		if (strcmp(args[0], "exit") == 0)
		{
			free(line);
			exit(0);
		}

		status = execute_command(args);
		if (status == 127)
		{
			free(line);
			exit(127);
		}
	}

	free(line);
	return (0);
}
