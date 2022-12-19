#include "monty.h"

/**
 * op_push - adds an element to the top of a stack.
 * @stack: address of the top poiner of the stack.
 * @line_number: The number of line of the the opcode.
 */
void op_push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int n;

	if (opcode_info.arg == NULL || !(is_tog(opcode_info.arg, _IS_NUMBER)))
		exit_error_msg(_MONTY_PUSH_USAGE, NULL);
	n = atoi(opcode_info.arg);
	free(opcode_info.arg);
	opcode_info.arg = NULL;
	if (opcode_info.mode == 'S')
		push_stack_elt(stack, n);
	if (opcode_info.mode == 'Q')
		add_elt_end(stack, n);
}

/**
 * op_pall - prints all elements of the stack.
 * @stack: address of the top poiner of the stack.
 * @line_number: The number of line of the the opcode in the file.
 */
void op_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack != NULL)
		print_stack_t(*stack);
}

/**
 * op_pint - prints the element n of the node at the top.
 * @stack: address of the top pointer of the stack.
 * @line_number: The number of the line of the opcode in the file.
 */
void op_pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (*stack == NULL)
		exit_error_msg(_MONTY_PINT_STACK_EMPTY, NULL);
	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - removes the top element of the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The number of the line of the opcode in the file.
 */
void op_pop(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (delete_elt_at_index(stack, 0) == -1)
		exit_error_msg(_MONTY_POP_EMPTY_STACK, NULL);
}
/**
 * op_swap - swaps the values of the top first two elements in the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The number of the line of the opcode int the file.
 */
void op_swap(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *first = NULL, *second  = NULL;
	int tmp;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
		exit_error_msg(_MONTY_SWAP_STACK_TOO_SHORT, NULL);
	tmp = first->n;
	first->n = second->n;
	second->n = tmp;
}
