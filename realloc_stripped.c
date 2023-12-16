#include "monty.h"
/**
 * extend - increases the size of a pointer to a given size
 * @mem: pointer to be extended
 * @new_size: new size to be allocated the pointer
 *
 * Return: void pointer
 */
void *extend(void *mem, size_t new_size)
{
	size_t n, old_size = sizeof(mem);
	void *mem2;
	unsigned char *byte_mem, *byte_mem2;

	mem2 = malloc(new_size);
	if (mem2 == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (mem)
	{
		byte_mem = (unsigned char *)mem;
		byte_mem2 = (unsigned char *)mem2;

		for (n = 0; n < old_size; n++)
			byte_mem[n] = byte_mem2[n];
		free(mem);
	}
	return (mem2);
}
