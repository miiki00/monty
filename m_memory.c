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
 * free_stack_t - frees a memory that is held by a list type of stack_t.
 * @head: The head of the list.
 *
 * Return: Void.
 */
void free_stack_t(stack_t *head)
{
	stack_t *tmp = NULL;

	if (head == NULL)
		return;
	for ( ; head != NULL; head = tmp)
	{
		tmp = head->next;
		free(head);
	}
}
