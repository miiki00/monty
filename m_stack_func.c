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
 * pint - function that prints the top of the stack
 * @head: double head pointer to the stack
 * @counter: line count
 *
 * Return: nothing
 */
stack_t pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(opcode_i.file);
		free(line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
