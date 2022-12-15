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
	{
		if (exact_match(opcode, arg_opcodes[i]))
			return (1);
	}
	for (i = 0; nonarg_opcodes[i] != NULL; i++)
	{
		if (exact_match(opcode, nonarg_opcodes[i]))
			return (0);
	}
	return (-1);
}

/**
 * build_instructions - builds array of instraction_t type
 * with intialized values.
 *
 * Return: array of instruction_t type (success), else exit.
 */
instruction_t **build_instructions(void)
{
	int i;

	void (*f[])(stack_t **, unsigned int) = {
		&push, &pall, NULL
	};
	char *opcodes[] = {
		"push", "pall", NULL
	};
	instruction_t **instructions = monty_malloc(sizeof(instruction_t *) * 3);

	for (i = 0; opcodes[i] != NULL; i++)
	{
		instructions[i] = monty_malloc(sizeof(instruction_t));
		(instructions[i])->opcode = opcodes[i];
		(instructions[i])->f = f[i];
	}
	instructions[i] = NULL;
	return (instructions);

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
	int i;
	instruction_t **instructions = NULL;

	/* validation if necessary */

	instructions = build_instructions();
	for (i = 0; instructions[i] != NULL; i++)
	{
		if (exact_match(opcode, (instructions[i])->opcode))
		{
			free(opcode);
			(instructions[i])->f(stack, line_number);
			free(instructions[i]);
		}
	}
}
