#include "monty.h"

/**
 * p_err - prints error message
 * @line_num: line number in file
 */

void p_err(int line_num)
{
	dprintf(2, "L%d: unknown instruction %s\n", line_num, line_tokens_arr[0]);
	exit(EXIT_FAILURE);
}
