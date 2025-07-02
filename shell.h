#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>


extern char **environ;

void tokenize(char *line, char **args);
int execute_command(char **args);
char *get_path_from_environ(void);
char *find_path(char *command);
int _strcmp(char *s1, char *s2);
int _is_number(char *s);
int _atoi(char *s);
int handle_exit_env(char **args, char *line, int *status);
int process_line(char *line, char **args, int *status);

#endif /* SHELL_H */
