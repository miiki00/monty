#include "monty.h"

/**
 * init_stack_elt - initializes a node for a struct stack_t.
 * @n: The valuse to assign to the node element n.
 * @next: The value to assigne to the node element next.
 * @prev: The value to assigne to the node element prev.
 *
 * Return: The node address (success), NULL (faliure).
 */
stack_t *init_stack_elt(int n, stack_t *next, stack_t *prev)
{
	stack_t *new = NULL;

	new = monty_malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = prev;
	new->next = next;

	return (new);
}

/**
 * stack_len - measures the length of a stack_t list type.
 * @h: The head of the list.
 *
 * Return: The length of the list.
 */
size_t stack_len(const stack_t *h)
{
	size_t len;

	for (len = 0; h != NULL; h = h->next)
		len++;
	return (len);
}
