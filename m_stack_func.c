#include "monty.h"

/**
 * print_stack_t - print a list kind of stack_t
 * @h: The head of the list.
 *
 * Return: The length of the list.
 */
size_t print_stack_t(const stack_t *h)
{
	size_t len;

	if (h == NULL)
		return (0);
	for (len = 0; h != NULL; h = h->next, len++)
		printf("%d\n", h->n);
	return (len);
}

/**
 * push_stack_elt - adds an element to the begining of a stack
 * implements with list type of stack_t.
 * @head: The address of the head pointer.
 * @n: The value to assign to the new stack element.
 *
 * Return: The address of the new element (success), NULL (error).
 */
stack_t *push_stack_elt(stack_t **head, const int n)
{
	stack_t *new = NULL;

	if (head == NULL)
		return (NULL);
	new = monty_malloc(sizeof(stack_t));
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * delete_elt_at_index - deletes a node from a list.
 * @head: Address of the head pointer of the list.
 * @index: The index of the node to be deleted.
 *
 * Return: 1 (success), -1 (error).
 */
int delete_elt_at_index(stack_t **head, unsigned int index)
{
	size_t idx;
	stack_t *next = NULL, *prev = NULL, *self = NULL;

	if (head == NULL || *head == NULL)
		return (-1);
	for (self = *head, idx = 0; self != NULL; self = self->next, idx++)
	{
		if (idx == index)
		{
			next = self->next;
			prev = self->prev;
			if (next != NULL)
				next->prev = prev;
			if (prev != NULL)
				prev->next = next;
			if (index == 0)
				*head = next;
			free(self);
			return (1);
		}
	}
	return (-1);
}

/**
 * add_elt_end - adds a node at the end of a list type of stack_t.
 * @head: The address of the pointer that holdes the head of the list.
 * @n: The value to assigne to the new nodes element.
 *
 * Return: The address of the new node (success), NULL (error).
 */
stack_t *add_elt_end(stack_t **head, const int n)
{
	stack_t *new = NULL;
	stack_t *cnt = NULL;

	if (head == NULL)
		return (NULL);
	new = init_stack_elt(n, NULL, NULL);
	for (cnt = *head; ; cnt = cnt->next)
	{
		if (cnt == NULL)
		{
			*head = new;
			return (new);
		}
		if (cnt->next == NULL)
		{
			cnt->next = new;
			new->prev = cnt;
			return (new);
		}
	}
}

/**
 * get_elt_at_index - gets a node at given index form a given list.
 * @head: The head of the list.
 * @index: The index of the node.
 *
 * Return: The address of the node (success), NULL (error).
 */
stack_t *get_elt_at_index(stack_t *head, unsigned int index)
{
	size_t idx;

	if (head == NULL)
		return (NULL);
	for (idx = 0; head != NULL; head = head->next, idx++)
		if (idx == index)
			return (head);
	return (NULL);
}
