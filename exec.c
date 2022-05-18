#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * exec - excecutes commands
 * @argv: an array of command and args
 *
 * Return: 1
 */
void exec(char **argv)
{
	pid_t pid = fork();
/*	char *envp[] = {(char *) "PATH=/bin", 0};*/

	if (pid == -1)
	{
		printf("\nFailed to fork");
		return;
	}
	else if (pid == 0)
	{

		if (execve(argv[0], argv, NULL) == -1)
			perror(argv[0]);
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}
/**
 * main - Start the excecution
 *
 * Return: 0 on success
 */

int main(void)
{
	char *command;
	char **args;
	int i;

	while (1)
	{
		command = get_prompt();
		for (i = 0; command[i] != '\0'; i++)
		{
			if (command[i] == 10)
				command[i] = ' ';
		}
		args = split_line(command);
		if (args[0] == NULL)
			continue;
		exec(args);
	}
	return (0);
}
