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
			perror("Error:");
		exit(0);
	}
	else {
		wait(NULL);
		return;
	}
}

int main(void)
{
	char *command;
	char **args;
/*
	while(1)
	{
		command = get_prompt();
		args = split_line(command);
		exec(args);

		printf("%s", args[1]);
		break;
		if (execve(args[0], args, NULL) == -1) 
			perror("Error:");

	}*/
	
	command = get_prompt();
	printf("%s", command);
	args = split_line(command);
	char *arg[] = {"a\n", NULL};

	int var;
	var = strcmp(arg[0], args[0]);
	printf("%d\n", var);

/*	exec(arg);*/
	return (0);
}
