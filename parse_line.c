#include "monty.h"
/**
 * get_toks - processes line of string read from file
 * @file_line: string containing line read from file
 * @delimiters: delimiters for tokenizing file_line
 *
 * Return: void
 */

char **get_toks(char *file_line, char *delimiters)
{
	size_t n = 0, len = 1;
	char *line_token;
	char **line_tokens_arr;
	char *dup_line = strdup(file_line);

	line_tokens_arr = malloc(sizeof(char *));
	if (line_tokens_arr == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*rm_newline(file_line);*/
	line_token = strtok(dup_line, delimiters);

	while (line_token != NULL)
	{
		line_tokens_arr = extend(line_tokens_arr, sizeof(char *) * (len + 1),
				sizeof(char *) * len);
		line_tokens_arr[n] = line_token;
		line_token = strtok(NULL, delimiters);
		len++;
		n++;
	}
	line_tokens_arr[n] = NULL;

	/*
	*for (n = 0; line_tokens_arr[n] != NULL; n++)
	*	printf("%s\n", line_tokens_arr[n]);
	*/

	return (line_tokens_arr);
}
