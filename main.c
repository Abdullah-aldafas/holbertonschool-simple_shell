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
	int status = 0;

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
		if (_strcmp(args[0], "exit") == 0)
		{
			if (args[1])
			{
				if (!_is_number(args[1]))
				{
					fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", args[1]);
					status = 2;
					continue;
				}
				status = _atoi(args[1]);
			}
			free(line);
			exit(status);
		}





		if (strcmp(args[0], "env") == 0)
		{
			int i = 0;
			while (environ[i])
			{
				printf("%s\n", environ[i]);
				i++;
			}
			continue;
		}
		status = execute_command(args);
	}
	free(line);
	return (status);
}
