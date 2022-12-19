#ifndef MONTY_H
#define MONTY_H
/* main header collection of monty 0.98 */

/* standard library headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representatino of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue).
 *
 * Description: doubly linked list node structure.
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function.
 * @opcode: the code.
 * @f: function to handle the opcode.
 *
 * Description: opcode and itsfunction
 * for stack, queues, LIFO, FIFO.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct opcode_info - contains information about an opcode.
 * @file: FILE * of the file from which opcode is being readed from.
 * @opcode: the opcode which this information is about.
 * @arg: if there is argument to the opcode this is where it gets stored.
 * @line_number: the current line of the opcode in the file.
 * @stack: the head of the stack which the opcode is operates on.
 * @mode: The current mode of stack opcodes operate on.
 * The first and the default is stack mod where the properties of LIFO
 * are applied.
 * And the second one is the queue mode wher the propertied of FIFO are
 * applied.
 */
typedef struct opcode_info
{
	FILE *file;
	char *opcode;
	char *arg;
	unsigned int line_number;
	stack_t **stack;
	char mode;
} opcode_i;

/* local library headers */
#include "m_opcode.h"
#include "m_error.h"
#include "m_memory.h"
#include "m_string.h"
#include "m_exec_opcode.h"
#include "m_stack_func.h"

/* function declarations */
void check_main_args(int ac, char **av);
FILE *open_file(char *path, char *flags);

/* global variables */
extern opcode_i opcode_info;

#endif
