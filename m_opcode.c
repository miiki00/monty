#include "monty.h"

/**
 * op_push - adds an element to the top of a stack.
 * @stack: address of the top poiner of the stack.
 * @line_number: The number of line of the the opcode.
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int n, arg_s = _M_FLS;

	if (opcode_info.arg == NULL || !(is_tog(opcode_info.arg, _IS_NUMBER)))
	{
		if (opcode_info.arg != NULL)
			arg_s = _M_TRU;
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_exit(_M_TRU, _M_TRU, arg_s, _M_FLS, EXIT_FAILURE);
	}
	n = atoi(opcode_info.arg);
	free(opcode_info.arg);
	push_stack_elt(stack, n);
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
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_exit(_M_TRU, _M_FLS, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - removes the top element of the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The number of the line of the opcode in the file.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	if (delete_elt_at_index(stack, 0) == -1)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
}
/**
 * op_swap - swaps the values of the top first two elements in the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The number of the line of the opcode int the file.
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second  = NULL;
	int tmp;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
	tmp = first->n;
	first->n = second->n;
	second->n = tmp;
}
