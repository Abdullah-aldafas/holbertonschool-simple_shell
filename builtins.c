#include "shell.h"

/**
 * handle_exit_env - Handles built-in commands: exit and env
 * @args: Array of command and its arguments
 * @line: The input line (to free if exiting)
 * @status: Pointer to status variable to exit with
 *
 * Return: 1 if built-in command was handled, 0 otherwise
 */
int handle_exit_env(char **args, char *line, int *status)
{
	int i;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1])
		{
			if (!_is_number(args[1]))
			{
				fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", args[1]);
				free(line);
				exit(2);
			}
			*status = _atoi(args[1]);
		}
		free(line);
		exit(*status % 256);
	}

	if (_strcmp(args[0], "env") == 0)
	{
		i = 0;
		while (environ[i])
			printf("%s\n", environ[i++]);
		return (1);
	}

	return (0);
}
