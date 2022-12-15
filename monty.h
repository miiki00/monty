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
extern char *G_arg;

#endif
