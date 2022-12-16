#include "monty.h"

/**
 * op_add - adds the top two elements of the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode in the file.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	int sum_n;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
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
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	int diff_n;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
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
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	int quot_n;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
	if (!(first->n))
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
	quot_n = second->n / first->n;
	second->n = quot_n;
	delete_elt_at_index(stack, 0);
}

/**
 * op_mul - multiplies the top two elements of the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode in the file.
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	int prod_n;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
	prod_n = first->n * second->n;
	second->n = prod_n;
	delete_elt_at_index(stack, 0);
}
