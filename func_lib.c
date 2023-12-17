#include "monty.h"

/**
 * p_err - prints error message
 * @line_num: line number in file
 * @code: invalid opcode
 */

void p_err(int line_num, char *code)
{
	dprintf(2, "L%d: unknown instruction %s\n", line_num, code);
	exit(EXIT_FAILURE);
}
