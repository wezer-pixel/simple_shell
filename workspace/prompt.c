#include "shell.h"

int main(void)
{
	char cmd[100], command[100], *parameters[20];
	char *envp[] = {(char *) "PATH=/bin", 0};

	while (1)
	{
		type_prompt();
		read_command (command, parameters);
		if (fork() != 0) /*parent*/
			wait(NULL); /*wait for child*/
		else
		{
			strcpy (cmd, "/bin/");
			strcat (cmd, command);
			execve (cmd, parameters, envp); /*execute command*/
		}
		if (strcmp (command, "exit") == 0)
		{
			break;
		}

		memset(command, 0, sizeof(command));
		memset(parameters, 0, sizeof(parameters));
	}
	return (0);
}

