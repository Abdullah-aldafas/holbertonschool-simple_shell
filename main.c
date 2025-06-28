#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int i;

	while (1)
	{
		printf("$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			break;
		}

		line[read - 1] = '\0';

		args = split_line(line);

		if (args[0] != NULL)
			execute(args);

		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}

	return (0);
}
