#include "monty.h"

/**
 * pall - prints elements in stack
 * @stack: address of top of stack
 * @line_number: line number in file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		return;
	printf("%d\n", (*stack)->n);
	pall(&(*stack)->prev, line_number);
}
