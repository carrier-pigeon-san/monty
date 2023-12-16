#include "monty.h"
/**
 * parse_tokens - validates opcode tokens before calling corresponding function
 * @opcode_tokens: list of tokens comprising the opcode
 * @line_number: index of line from which opcodes were read
 *
 * Return: void
 */
void parse_tokens(char **opcode_tokens, int line_number)
{
	void (*fnc_def)(stack_t **stack, unsigned int line_number);
	static stack_t *head = NULL;
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
				dprintf(2, "L%d: usage: push integer", line_number);
			}
			fnc_def(&head, atoi(opcode_tokens[1]));
		}
		else
			fnc_def(&head, line_number);

	}
	else
	{
		/*printf("route 2\n");*/
		p_err(line_number, opcode_tokens[0]);
	}
}
