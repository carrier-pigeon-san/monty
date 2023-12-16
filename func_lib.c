#include "monty.h"

/**
 * p_err - prints error message
 * @line_num: line number in file
 */

void p_err(int line_num, char *code)
{
	dprintf(2, "L%d: unknown instruction %s\n", line_num, code);
	exit(EXIT_FAILURE);
}

void rm_newline(char *str)
{
	char *new_str;
	int n;

	new_str = malloc(sizeof(char *));
	if (new_str == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (str)
	{
		for (n = 0; new_str[n] != '\n'; n++)
			new_str[n] = str[n];
		str = new_str;
	}
}
