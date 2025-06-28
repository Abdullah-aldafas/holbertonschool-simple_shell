#include "shell.h"

/**
 * execute - Forks and executes the given command
 * @args: NULL-terminated array of arguments (e.g. {"ls", "-l", NULL})
 */
void execute(char **args)
{
	pid_t pid;
	char *cmd_path;

	cmd_path = find_path(args[0]);  /* Get full path from PATH */

	if (!cmd_path)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}

	pid = fork();  /* Create a child process */

	if (pid == 0)  /* Child process */
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)  /* Parent process */
	{
		wait(NULL);  /* Wait for child to finish */
		free(cmd_path);  /* Free command path */
	}
	else
	{
		perror("fork");
	}
}
