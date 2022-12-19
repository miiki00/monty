#include "monty.h"

/**
 * op_stack - changes the mode of the stack into LIFO.
 * @stack: address of the top poiner of the stack.
 * @line_number: The number of line of the the opcode.
 */
void op_stack(__attribute((unused))stack_t **stack,
			__attribute((unused))unsigned int line_number)
{
	opcode_info.mode = 'S';
}

/**
 * op_queue - changes the mode of the stack into FIFO.
 * @stack: address of the top poiner of the stack.
 * @line_number: The number of line of the the opcode.
 */
void op_queue(__attribute((unused))stack_t **stack,
			__attribute((unused))unsigned int line_number)
{
	opcode_info.mode = 'Q';
}
