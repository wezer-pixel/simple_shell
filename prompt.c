#include "shell.h"
#include <sys/wait.h>
/**
 * prompt - prompts the user to insert command
 * @av: argument vector
 * @env: environment variable
 */
void prompt(char **av, char **env)
{
	char *string = NULL;
	int status, i;
	size_t n = 0;
	ssize_t num_char;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;

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

		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0;
			i++;
		}

		argv[0] = string;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
		if (execve(argv[0], argv, env) == -1)
		{
			printf("%s: No such file or directory\n", av[0]);
		}

		}
		else
		{
			wait(&status);
		}
	}
}
