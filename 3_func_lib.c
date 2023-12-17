#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of code in file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp_node = *stack;
	*stack = (*stack)->next;
	if ((*stack)->next == NULL)
		temp_node->next = NULL;
	else
		temp_node->next = (*stack)->next;
	temp_node->prev = *stack;
	(*stack)->next->prev = temp_node;
	(*stack)->next = temp_node;
	(*stack)->prev = NULL;
}
