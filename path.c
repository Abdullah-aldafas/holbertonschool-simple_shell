#include "shell.h"

/**
 * find_path - Searches for a command in the directories of PATH
 * @command: The name of the command (e.g. "ls")
 *
 * Return: Full path to the command if found, or NULL
 */
char *find_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir, *full_path;
	size_t len;

	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");

	while (dir)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)  /* Check if executable */
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
