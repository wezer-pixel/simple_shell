/**
 * _getline - read one line from the prompt.
 * @data: struct for the program's data
 *
 * This function reads a line from the prompt and performs various operations on it.
 * It checks for logical operators (&& and ||) and splits the line accordingly.
 * If there are no more commands in the array or if the previous command was successful (for &&) or unsuccessful (for ||),
 * it frees the memory allocated in the array and reads from the file descriptor into a buffer.
 * The lines are then split based on newline or semicolon characters.
 * The function also checks for && and || operators within each command and splits the line accordingly.
 * The next command (command 0) is obtained and removed from the array.
 *
 * Return: The number of bytes read from the prompt.
 */
int _getline(data_of_program *data)
{
	// Function implementation
}

/**
 * check_logic_ops - checks and split for && and || operators
 * @array_commands: array of the commands.
 * @i: index in the array_commands to be checked
 * @array_operators: array of the logical operators for each previous command
 *
 * This function checks each command in the array for the presence of && and || operators.
 * If an operator is found, it splits the line accordingly and updates the array and operator arrays.
 * It then returns the index of the last command in the array.
 *
 * Return: The index of the last command in the array_commands.
 */
int check_logic_ops(char *array_commands[], int i, char array_operators[])
{
	// Function implementation
}
#include "shell.h"

/**
* _getline - read one line from the prompt.
* @data: struct for the program's data
*
* Return: reading counting bytes.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	/* check if doesnot exist more commands in the array */
	/* and checks the logical operators */
	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		/*free the memory allocated in the array if it exists */
		for (i = 0; array_commands[i]; i++)
		{
			free(array_commands[i]);
			array_commands[i] = NULL;
		}

		/* read from the file descriptor int to buff */
		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		/* split lines for \n or ; */
		i = 0;
		do {
			array_commands[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;"));
			/*checks and split for && and || operators*/
			i = check_logic_ops(array_commands, i, array_operators);
		} while (array_commands[i++]);
	}

	/*obtains the next command (command 0) and remove it for the array*/
	data->input_line = array_commands[0];
	for (i = 0; array_commands[i]; i++)
	{
		array_commands[i] = array_commands[i + 1];
		array_operators[i] = array_operators[i + 1];
	}

	return (str_length(data->input_line));
}


/**
* check_logic_ops - checks and split for && and || operators
* @array_commands: array of the commands.
* @i: index in the array_commands to be checked
* @array_operators: array of the logical operators for each previous command
*
* Return: index of the last command in the array_commands.
*/
int check_logic_ops(char *array_commands[], int i, char array_operators[])
{
	char *temp = NULL;
	int j;

	/* checks for the & char in the command line*/
	for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
	{
		if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
		{
			/* split the line when chars && was found */
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = str_duplicate(array_commands[i]);
			array_commands[i + 1] = str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
		{
			/* split the line when chars || was found */
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = str_duplicate(array_commands[i]);
			array_commands[i + 1] = str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
