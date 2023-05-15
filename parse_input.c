#include "shell.h"

#define MAX_ARGS 10

/**
 * parse_input - parses the input string into individual command arguments
 * @input: input string
 * @argv: array to store command arguments
 */
void parse_input(char *input, char **argv)
{
	int i = 0;

	argv[i] = strtok(input, " ");
	while (argv[i] != NULL && i < MAX_ARGS - 1)
	{
		argv[++i] = strtok(NULL, " ");
	}
	argv[i] = NULL;
}
