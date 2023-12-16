#include "monty.h"
/**
 * if_valid - checks validity of instruction line
 * @str_tokens: array of strings containing tokens that make up instruction
 *
 * Return: 1 (valid), 0 (invalid)
 */
int if_valid(char *str_tokens[])
{
	int n, arg, is_zero;

	for (n = 0; str_tokens[n] != NULL; n++)
		;
	if (n < 2)
		return (0);
	arg = atoi(str_tokens[1]);
	is_zero = strcmp(str_tokens[1], "0");
	if (arg == 0 && is_zero != 0)
		return (0);

	return (1);
}
