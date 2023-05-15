#include "shell.h"

#define MAX_ARGS 10

/**
 * prompt - prompts the user to insert command
 * @av: argument vector
 * @env: environment variable
 */
void prompt(char **av, char **env)
{
	char *string = NULL;
	size_t n = 0;
	ssize_t num_char;
	char *argv[MAX_ARGS];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		if (string[num_char - 1] == '\n')
			string[num_char - 1] = '\0';

		parse_input(string, argv);
		execute_command(argv, env, av);
	}
}
