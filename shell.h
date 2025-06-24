#ifndef SHELL_H
#define SHELL_H
/*
 * File: shell.h
 * Desc: Prototypes and libraries for a simple shell program.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * tokenize - Splits a line into words
 * @line: The input line to split
 * @args: The resulting array of words
 *
 * Description: Tokenizes the input line into separate words.
 * This function fills the args array with each word from line.
 */
void tokenize(char *line, char **args);
/**
 * execute_command - Executes a given command
 * @args: Array of command and its arguments
 *
 * Description: Creates a child process and executes the command
 * using execve. Parent waits for the child to finish.
 */
void execute_command(char **args);
#endif /* SHELL_H */
