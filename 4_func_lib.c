#include "monty.h"
/**
 * mul - multiplies the two top elements of the stack
 * @stack: double pointer to top of the stack
 * @line_number: line number of code in file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n * (*stack)->prev->n;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 * mod - computes mod of division of second top element by the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of code in file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n % (*stack)->prev->n;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 * free_stack - deallocated stack memory
 * @stack: pointer to top of stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = stack;

	while (temp != NULL)
	{
		stack = stack->next;
		free(temp);
		temp = stack;
	}
}
/**
 * pchar - prints the char at the top of the stack
 * @stack: double pointer to top of stack
 * @line_number: line number of opcode in file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - prints string starting at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of opcode in file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	do {
		if (temp->n >= 1 && temp->n <= 127)
			printf("%c", temp->n);
		else
			break;
		temp = temp->next;
	} while (temp != NULL);
	printf("\n");
}
