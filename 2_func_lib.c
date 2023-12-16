#include "monty.h"
/**
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
 */
void pall(stack_t **stack, unsigned int line_number)
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
