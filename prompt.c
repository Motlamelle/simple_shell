#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * get_prompt- read a command from std input
 *
 * Return: the command
 */

char *get_prompt(void)
{
	char *buf;
	size_t size = 64;
	ssize_t c;

	buf = malloc(sizeof(char) * size);

	if (!buf)
	{
		perror("Malloc failed\n");
		exit(1);
	}

	printf("$ ");
	c  = getline(&buf, &size, stdin);

	if (c == EOF)
	{
		exit(0);
	}

	return (buf);
}

/**
 * split_line- splits a command line into strings
 * @str: input line
 *
 * Return: Array of strings
 */

char **split_line(char *str)
{
	int i = 0;
	int bufsize = 64;
	char *res;

	char **tokens = malloc(bufsize * sizeof(char *));
	/*get first token */
	tokens[i++] = strtok(str, " ");

	/*get all other tokens */
	while ((res = strtok(NULL, " ")))
	{
		tokens[i++] = res;
	}

	tokens[i] = NULL;

	return (tokens);
}

/**
 * exit_shell - exits the shell
 *
 * Return: 0
 */

int exit_shell(void)
{
	return (0);
}
