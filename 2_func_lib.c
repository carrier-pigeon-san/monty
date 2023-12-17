#include "monty.h"
/**
 * make_node - create new stack_t node
 *
 * Return: pointer to new node
 */
stack_t *make_node(void)
{
	stack_t *new_entry;

	new_entry = malloc(sizeof(stack_t));
	if (new_entry == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_entry->n = 0;
	new_entry->next = NULL;
	new_entry->prev = NULL;
	return (new_entry);
}
/**
 * push - pushes an element to the stack
 * @stack: head of stack
 * @line_number: value of stack
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_entry;

	new_entry = malloc(sizeof(stack_t));
	if (new_entry == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_entry->n = line_number;
	new_entry->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_entry;
	*stack = new_entry;
}
/**
 * pall - prints all the stack values, starting from the top of the stack
 * @stack: top of the stack
 * @line_number: value of the stack
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		stack_t *temp_entry;

		(void)line_number;
		temp_entry = *stack;

		while (temp_entry != NULL)
		{
			printf("%d\n", temp_entry->n);
			temp_entry = temp_entry->next;
		}
	}
}
/**
 * pint - prints value at the top of the stack followed by a new line
 * @stack: top of the stack
 * @line_number: node value
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
