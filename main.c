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
	char *hash = strchr(line, '#');

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		if (getline(&line, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(status % 256);
		}

		line[strcspn(line, "\n")] = '\0';
		if (line && line[0] != '\0')
		{
			char *hash = strchr(line, '#');
			if (hash && (hash == line || *(hash - 1) == ' '))
				*hash = '\0';
		}
		if (hash && (hash == line || *(hash - 1) == ' '))
			*hash = '\0';

		if (line[0] == '\0' || line[0] == '#')
			continue;

		tokenize(line, args);
		if (args[0] == NULL || args[0][0] == '#')
			continue;

		if (handle_exit_env(args, line, &status))
			continue;

		status = execute_command(args);
	}
	free(line);
	return (status % 256);
}
