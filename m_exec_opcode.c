#include "monty.h"

/**
 * check_opcode - checks if opcode takes argument or not or if
 * it even exists.
 * @opcode: the opcode to check.
 *
 * Return: 1 (opcode takes argument), 0 (opcode doesn't take arguments),
 * -1 (opcode doesn't exist).
 */
int check_opcode(char *opcode)
{
	int i;
	char *arg_opcodes[] = {
		"push", NULL
	};
	char *nonarg_opcodes[] = {
		"pall", NULL
	};

	if (opcode == NULL)
		return (0);
	for (i = 0; arg_opcodes[i] != NULL; i++)
		if (exact_match(opcode, arg_opcodes[i]))
			return (1);
	for (i = 0; nonarg_opcodes[i] != NULL; i++)
		if (exact_match(opcode, nonarg_opcodes[i]))
			return (0);
	return (-1);
}

/**
 * execute_opcode - executes an opcode.
 * @stack: the for the opcode to operate on.
 * @opcode: the opcode to executed.
 * @line_number: the number of the line the opcode was found on.
 *
 * Return: if it returns to the caller (successful), else
 * it will exit print an error message.
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", &push}, {"pall", &pall}
	};
	int i;

	for (i = 0; i < OPCODES_N; i++)
	{
		if (exact_match(opcode, (instructions[i]).opcode))
		{
			free(opcode);
			(instructions[i]).f(stack, line_number);
			break;
		}
	}
}
