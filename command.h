#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char **args);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void parse_command(char  *command);
#endif
