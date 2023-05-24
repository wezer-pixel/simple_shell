#include "command.h"

/**
 * execute_command - executes comand input in terminal
 * @args: Argument in terminal
 * Return: 0 to child and error to parent process
 */

void execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error executing command");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error forkinf");
	}
	else
		wait(NULL);
}
