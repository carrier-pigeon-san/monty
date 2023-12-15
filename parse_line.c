#include "monty.h"
/**
 * parse_line - processes line of string read from file
 * @file_line: string containing line read from file
 * @line_num: number of line in the file
 *
 * Return: void
 */
void parse_line(char *file_line, int line_num)
{
	size_t n = 0, len = 1;
	char *line_token;
	char **line_tokens_arr;

	line_tokens_arr = malloc(sizeof(char *));
	if (line_tokens_arr == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line_token = strtok(file_line, " ");

	while (line_token != NULL)
	{
		line_tokens_arr = extend(line_tokens_arr, sizeof(char *) * (len + 1));
		line_tokens_arr[n] = line_token;
		line_token = strtok(NULL, " ");
		len++;
		n++;
	}
	line_tokens_arr[n] = NULL;
}
