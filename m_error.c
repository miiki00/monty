#include "monty.h"

/**
 * exit_error_msg - exits the program after print the error message
 * corresponding to the error.
 * @code: the error code.
 * @add: additional info about the error.
 */
void exit_error_msg(int code, char *add)
{
	if (code < 110)
		level_one_error(code, add);
	else
		level_two_error(code, add);

	free_exit(EXIT_FAILURE);
}


/**
 * free_exit - exits the program after freeing memories retrieved
 * dynamically.
 * @_exit: The status you want to exit with.
 */
void free_exit(int _exit)
{
	if (opcode_info.file)
		fclose(opcode_info.file);
	if (opcode_info.stack)
		free_stack_t(*(opcode_info.stack));
	if (opcode_info.arg)
		free(opcode_info.arg);
	if (opcode_info.opcode)
		free(opcode_info.opcode);
	exit(_exit);
}

/**
 * level_one_error - prints error messages for early errors.
 * @code: The error code.
 * @add: additional info to the error.
 */
void level_one_error(int code, char *add)
{
	char *err_msg[] = {
		"USAGE: monty file", "Error: Can't open file ",
		"Error: malloc failed", NULL
	};
	int codes[] = {
		_MONTY_USAGE_ERR, _MONTY_UNABLE_TO_READ_FILE,
		_MONTY_MALLOC_FAILED, 100
	};
	int i;

	for (i = 0; codes[i] != 100; i++)
	{
		if (code == codes[i])
			fprintf(stderr, "%s", err_msg[i]);
		if (add != NULL && code == codes[i])
			fprintf(stderr, "%s", add);
		if (code == codes[i])
			break;
	}
	fprintf(stderr, "\n");
}

/**
 * level_two_error - prints error message for late errors.
 * @code: The error code.
 * @add: additonal information about the error.
 */
void level_two_error(int code, char *add)
{
	char *err_msg[] = {
		"usage: push integer", "can't pint, stack empty",
		"can't pop an empty stack", "can't swap, stack too short",
		"can't add, stack too short", "can't sub, stack too short",
		"can't div, stack too short", "divistion by zero",
		"unknown instruction ", "can't pchar, stack empty",
		"can't pchar, value out of range", "can't mul, stack too short",
		"can't mod, stack too short", NULL
	};

	int codes[] = {
		_MONTY_PUSH_USAGE, _MONTY_PINT_STACK_EMPTY,
		_MONTY_POP_EMPTY_STACK, _MONTY_SWAP_STACK_TOO_SHORT,
		_MONTY_ADD_STACK_TOO_SHORT, _MONTY_SUB_STACK_TOO_SHORT,
		_MONTY_DIV_STACK_TOO_SHORT, _MONTY_DIVISION_BY_ZERO,
		_MONTY_UNKNOWN_INSTRUCTION, _MONTY_PCHAR_STACK_EMPTY,
		_MONTY_PCHAR_VALUE_OUT_OF_RANGE, _MONTY_MUL_STACK_TOO_SHORT,
		_MONTY_MOD_STACK_TOO_SHORT, 100
	};
	int i;

	for (i = 0; codes[i] != 100; i++)
	{
		if (code == codes[i])
		{
			fprintf(stderr, "L%d: %s", opcode_info.line_number, err_msg[i]);
			if (add)
				fprintf(stderr, "%s", add);
			break;
		}
	}
	fprintf(stderr, "\n");
}
