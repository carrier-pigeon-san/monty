#include "monty.h"
/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 (Success), something else (otherwise)
 */
int main(int ac, char **av)
{
	FILE *bytefile;
	char *lineptr = NULL;
	size_t size = 0, line_count = 0;
	ssize_t line_len;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bytefile = fopen(av[1], "r");
	if (bytefile == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((line_len = getline(&lineptr, &size, bytefile)) != -1)
	{
		line_count++;
		if (line_len == 1)
			continue;
		/*printf("%ld\n", line_len);*/
		parse_line(lineptr, line_count);
	}
	fclose(bytefile);
	return (0);
}
