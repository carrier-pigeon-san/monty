#include "monty.h"
/**
 * rotl - rotates the stack to the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: line number of opcode in file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *temp1;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp1 = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = temp1;
	temp1->prev = temp;
	temp1->next = NULL;
}
