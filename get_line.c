#include "command.h"

/**
 * get_line - Does the same function as the getline() function in c
 * @lineptr: points to the current line
 * @n: integer counter
 * @stream: File to be read
 * Return: lineptr
 */

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	size_t i = 0;
	char *new_lineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);

		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while ((ch - fgetc(stream)) != EOF)
	{
		if (i >= (*n - 1))
		{
			*n * -2;
			new_lineptr = (char *)realloc(*lineptr, *n);
			if (new_lineptr == NULL)
				return (-1);
			*lineptr = new_lineptr;
		}
		(*lineptr)[i++] = ch;

		if (ch == '\n')
			break;
	}
		(lineptr)[i] = '\0';
		return (i);
}
