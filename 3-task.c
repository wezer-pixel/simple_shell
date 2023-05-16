#include "shell.h"

/**
 *main - prints out the files in a long list form
 *Description: The code separates function named path()
 *	that uses fork() and execve() to execute the "ls" command.
 *
 *Return: -1 if an error occurs and 0 ==> success
 */

int path(void)
{
	int val;

	pid_t pid;

	char *argv[] = {"/bin/ls", "-l", NULL};

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{

		val = execve(argv[0], argv, NULL);
		if (val == -1)
			perror("Command not found\n");
	}
	else
	{
		wait(NULL);
		printf("Done with execve\n");
	}

	return (0);
}
