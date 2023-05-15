#include "shell.h"

/**
 * execute_command - executes the command with the given arguments
 * @argv: array of command arguments
 * @env: environment variable
 * @av: argument vector
 */
void execute_command(char **argv, char **env, char **av)
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			printf("%s: No such file or directory\n", av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

