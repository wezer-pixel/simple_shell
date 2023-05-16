#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void prompt(char **av, char **env);
void parse_input(char *input, char **argv);
void execute_command(char **argv, char **env, char **av);
int path(void);

#endif
