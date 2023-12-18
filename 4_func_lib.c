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
/**
 * mod - computes mod of division of second top element by the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of code in file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n % (*stack)->prev->n;
	(*stack)->prev = NULL;
}
