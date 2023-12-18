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
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
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
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of code in file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n + (*stack)->prev->n;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 * nop - does nothing
 * @stack: pointer to top of stack
 * @line_number: line number of code in file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the code in file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n - (*stack)->prev->n;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 * divide - divide the second top element of the stack by the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of code in file
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n / (*stack)->prev->n;
	(*stack)->prev = NULL;
	free(temp);
}
