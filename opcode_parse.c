#include "monty.h"
/**
 * parse_tokens - validates opcode tokens before calling corresponding function
 * @opcode_tokens: list of tokens comprising the opcode
 * @line_number: index of line from which opcodes were read
 * @head: pointer to top of stack
 * @buffer: buffer holding instruction line read from file
 * @stream: bytefile
 *
 * Return: void
 */
void parse_tokens(char **opcode_tokens, int line_number, stack_t **head,
		char *buffer, FILE *stream)
{
	void (*fnc_def)(stack_t **stack, unsigned int line_number);
	int is_valid;

	fnc_def = sect_func(opcode_tokens[0]);
	if (fnc_def)
	{
		if (fnc_def == &push)
		{
			is_valid = if_valid(opcode_tokens);
			if (is_valid == 0)
			{
				dprintf(2, "L%d: usage: push integer\n", line_number);
				if (*head)
					free_stack(*head);
				if (opcode_tokens)
					free(opcode_tokens);
				free(buffer);
				fclose(stream);
				exit(EXIT_FAILURE);
			}
			fnc_def(head, atoi(opcode_tokens[1]));
		}
		else
			fnc_def(head, line_number);
	}
	else
	{
		dprintf(2, "L%d: unknown instruction %s\n", line_number, opcode_tokens[0]);
		if (*head)
			free_stack(*head);
		free(opcode_tokens);
		free(buffer);
		fclose(stream);
		exit(EXIT_FAILURE);
	}
	if (opcode_tokens)
	{
		free(opcode_tokens);
	}

}
