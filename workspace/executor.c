#include "shell.h"

void type_prompt()
{
	static int first_time = 1;
	const char* CLEAR_SCREEN_ANSI;

	if (first_time) /*clear screen for the 1st time*/
	{
		CLEAR_SCREEN_ANSI = "\033[1;1H\033[2J";
		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}

	printf("And Jerry says: "); /*display prompt*/
}
