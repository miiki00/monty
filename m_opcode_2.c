#include "monty.h"

/**
 * op_mod - divides the second top element of the stack by the top
 * element of the stack and get the remainder.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode int the file.
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	int mod_n;

	first = get_elt_at_index(*stack, 0);
	second = get_elt_at_index(*stack, 1);
	if (!(first) || !(second))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
	if (!(first->n))
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
	mod_n = second->n % first->n;
	second->n = mod_n;
	delete_elt_at_index(stack, 0);
}

/**
 * op_pchar - prints the first element of the stack treating it as
 * it is in the ascii table.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode int the file.
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (ch > 127 ||  ch < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_exit(_M_TRU, _M_TRU, _M_FLS, _M_FLS, EXIT_FAILURE);
	}
	printf("%c\n", ch);
}

/**
 * op_pstr - prints string built of the elements of the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode int the file.
 */
void op_pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *copy = NULL;

	for (copy = *stack; copy != NULL; copy = copy->next)
	{
		if (copy->n <= 127 && copy->n > 0)
			putchar(copy->n);
		else
			break;
	}
	putchar('\n');
}

/**
 * op_rotl - moves the top element of the stack to the end.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode int the file.
 */
void op_rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (*stack != NULL)
	{
		if ((*stack)->next != NULL)
		{
			add_elt_end(stack, (*stack)->n);
			delete_elt_at_index(stack, 0);
		}
	}
}

/**
 * op_rotr - rotates the stack.
 * @stack: address of the top pointer of the stack.
 * @line_number: The line number of the opcode int the file.
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	size_t len, i;

	len = stack_len(*stack);
	if (*stack != NULL)
		for (i = 0; i < (len - 1); i++)
			op_rotl(stack, line_number);
}

