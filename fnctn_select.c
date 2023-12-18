#include "monty.h"
/**
 * sect_func - selects and calls function corresponding to opcode
 * @opcode: opcode/first token of command
 *
 * Return: function corresponding to opcode
 */
void (*sect_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t protos[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};
	int n;

	/*printf("Opcode: %s", opcode);*/
	for (n = 0; protos[n].opcode != NULL; n++)
	{

		if (strcmp((protos[n].opcode), opcode) == 0)
			return (protos[n].f);
	}
	return (NULL);
}
