#include "monty.h"
/**
 * parse_tokens - validates opcode tokens before calling corresponding function
 * @opcode_tokens: list of tokens comprising the opcode
 * @line_number: index of line from which opcodes were read
 * @head: pointer to top of stack
 *
 * Return: void
 */
void parse_tokens(char **opcode_tokens, int line_number, stack_t **head)
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
				/*printf("route 1\n");*/
				dprintf(2, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			fnc_def(head, atoi(opcode_tokens[1]));
		}
		else
			fnc_def(head, line_number);

	}
	else
	{
		/*printf("route 2\n");*/
		p_err(line_number, opcode_tokens[0]);
	}
	if (opcode_tokens)
	{
		free(opcode_tokens);
	}

}
