#include "monty.h"
/**
 * mul - multiplies the two top elements of the stack
 * @stack: double pointer to top of the stack
 * @line_number: line number of code in file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n * (*stack)->prev->n;
	(*stack)->prev = NULL;
}
