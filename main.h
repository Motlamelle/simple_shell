#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>

char *shell_prompt(char *, size_t, ssize_t *);
char **split_str(char *);
int exit_check(char *, ssize_t);
void command_exec(char *line, ssize_t nread);
#endif
