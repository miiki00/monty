#include "monty.h"

/**
 * push - adds an element to the top of a stack.
 * @stack: address of the top poiner of the stack.
 * @line_number: The number of line of the the opcode.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (opcode_info.arg == NULL || !(is_tog(opcode_info.arg, _IS_NUMBER)))
	{
		fclose(opcode_info.file);
		if (opcode_info.arg != NULL)
			free(opcode_info.arg);
		if (*stack != NULL)
			free_stack_t(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(opcode_info.arg);
	free(opcode_info.arg);
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
/**
 * pint - print top most element of the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The number of the line of the opcode.
 * Returns: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		pint(*stack);
}
