#include "shell.h"

/**
 * execute_command - Run a command using fork and execve
 * @args: Array of command and its arguments
 *
 * Forks a child process to run the command.
 * The parent waits for the child to finish.
 */
void execute_command(char **args)
{
	pid_t pid;
	char *cmd_path;

	if (args[0] == NULL)
		return;

	if (strchr(args[0], '/'))
		cmd_path = args[0];
	else
		cmd_path = find_path(args[0]);

	if (cmd_path == NULL)
	{
		fprintf(stderr, "./hsh: command not found\n");
		return;
	}

	pid = fork();

	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
	}
}
