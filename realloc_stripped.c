#include "monty.h"
/**
 * extend - increases the size of a pointer to a given size
 * @mem: pointer to be extended
 * @new_size: new size to be allocated the pointer
 * @old_size: previous size of memory to be extended
 *
 * Return: void pointer
 */
void *extend(void *mem, size_t new_size, size_t old_size)
{
	size_t n;
	void *mem2;
	unsigned char *byte_mem, *byte_mem2;

	mem2 = malloc(new_size);
	if (mem2 == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (mem)
	{
		byte_mem = (unsigned char *)mem;
		byte_mem2 = (unsigned char *)mem2;

		for (n = 0; n < old_size; n++)
			byte_mem2[n] = byte_mem[n];
		free(mem);
	}
	return (mem2);
}
