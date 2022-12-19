#include "monty.h"

/**
 * op_add - adds the top two elements of the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode in the file.
 */
void op_add(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	int sum_n;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
		exit_error_msg(_MONTY_ADD_STACK_TOO_SHORT, NULL);
	sum_n = first->n + second->n;
	second->n = sum_n;
	delete_elt_at_index(stack, 0);
}

/**
 * op_nop - does nothing.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode int the file.
 */
void op_nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{}

/**
 * op_sub - subtracts the top first nodes elt n from the second's.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode in the file.
 */
void op_sub(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	int diff_n;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
		exit_error_msg(_MONTY_SUB_STACK_TOO_SHORT, NULL);
	diff_n = second->n - first->n;
	second->n = diff_n;
	delete_elt_at_index(stack, 0);
}

/**
 * op_div - divides the second top element of the stack by the top
 * element of the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode int the file.
 */
void op_div(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	int quot_n;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
		exit_error_msg(_MONTY_DIV_STACK_TOO_SHORT, NULL);
	if (!(first->n))
		exit_error_msg(_MONTY_DIVISION_BY_ZERO, NULL);
	quot_n = second->n / first->n;
	second->n = quot_n;
	delete_elt_at_index(stack, 0);
}

/**
 * op_mul - multiplies the top two elements of the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode in the file.
 */
void op_mul(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	int prod_n;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
		exit_error_msg(_MONTY_MUL_STACK_TOO_SHORT, NULL);
	prod_n = first->n * second->n;
	second->n = prod_n;
	delete_elt_at_index(stack, 0);
}
