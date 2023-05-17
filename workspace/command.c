#include "shell.h"

void read_command (char cmd[], char *par[])
{
	char line[1024];
	int count = 0, i = 0, j, c;
	char *array[100], *pch;

	/*Read one line*/
	for(;;)
	{
		c = fgetc(stdin);
		line[count++] = (char) c;
		if (c == '\n')
			break;
	}

	if (count == 1)
	{
		pch = strtok(line, "\n");
		strcpy(cmd, pch);
		return;
	}

	else
	{
		/*parse the line into words*/
		pch = strtok(line, " \n");
		while (pch != NULL)
		{
			array[i++] = strdup(pch);
			pch = strtok (NULL, "\n");
		}
		strcpy (cmd, array[0]);

		for (j = 0; j < i; j++)
		{
			par[j] = array[j];
		}

		par[i] = NULL; /*terminate the parameter list*/
	}
}
