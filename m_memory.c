#include "monty.h"

/**
 * monty_malloc - allocates a memory size of @size if
 * malloc fail to alloca it will print an error message
 * and exit.
 * @size: The size of memory to allocate.
 *
 * Return: the address of the allocated memory (success)
 * does not return (error).
 */
void *monty_malloc(unsigned int size)
{
	void *memory = NULL;

	memory = malloc(size);
	if (memory == NULL)
		exit_error_msg(_MONTY_MALLOC_FAILED, NULL);
	return (memory);
}

/**
 * free_instructions - frees memory held by array of instructino_t type.
 * @instructions: the array of the instruction_t types.
 *
 * Return: void.
 */
void free_instructions(instruction_t **instructions)
{
	int i;

	if (*instructions == NULL)
		return;
	for (i = 0; instructions[i] != NULL; i++)
		free(instructions[i]);
	free(instructions);
}
