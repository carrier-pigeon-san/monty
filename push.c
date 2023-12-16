#include "monty.h"

/**
 * create_stack_node - creates a stack node
 * @n: value of stack node
 * Return: pointer to stack node
 * NULL if it failed
 */

stack_t *create_stack_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	return (new);
}

/**
 * push - pushes an element to top of stack
 * @stack: address of top of stack
 * @line_number: line number in file
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n = atoi(line_tokens_arr[1]);

	if (n == 0)
	{
		dprintf(2, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack == NULL)
	{
		*stack = create_stack_node(n);
	}

	new = create_stack_node(n);
	new->prev = *stack;
	*stack = new;
}
