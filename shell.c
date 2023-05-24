#include "command.h"

#define MAX_COMMAND_LENGTH 100
/**
 * parse_command - parses commands enterd in commandline
 * @command: accepts a command
 * Return: void
 */
void parse_command(char  *command)
{
	char *token = strtok(command, " \t\n");
	char *args[MAX_COMMAND_LENGTH];
	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	if (i > 0)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			exit(0);
		}
		else
		{
			execute_command(args);
		}
	}
}

/**
 * main - runs the shell
 * Return: 0 on sucess
 */
int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t line_size;

	while (1)
	{
		printf("cisfun$ ");
		line_size = getline(&command, &command_size, stdin);
		if (line_size == -1)
		{
			break;
		}
		parse_command(command);
	}
	free(command);
	return (0);
}
