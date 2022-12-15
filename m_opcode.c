#include "monty.h"

/**
 * push - adds an element to the top of a stack.
 * @stack: address of the top poiner of the stack.
 * @line_number: The number of line of the the opcode.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (G_arg == NULL || !(is_tog(G_arg, _IS_NUMBER)))
	{
		if (G_arg != NULL)
			free(G_arg);
		if (*stack != NULL)
			free_stack_t(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(G_arg);
	free(G_arg);
	push_stack_elt(stack, n);
}

/**
 * pall - prints all elements of the stack.
 * @stack: address of the top poiner of the stack.
 * @line_number: The number of line of the the opcode.
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack != NULL)
		print_stack_t(*stack);
}

