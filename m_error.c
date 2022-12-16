#include "monty.h"

/**
 * exit_error_msg - exits the program after print the error message
 * corresponding to the error.
 * @code: the error code.
 * @add: additional info about the error.
 */
void exit_error_msg(int code, char *add)
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
	exit(EXIT_FAILURE);
}

/**
 * free_exit - exits the program after freeing memories retrieved
 * dynamically.
 * @file: toggel for closing file descriptor.
 * @stack: toggel for freeing the memory held by the stack.
 * @arg: toggel for freeing the memory held by the argument passed
 * to the opcode.
 * @_exit: The status you want to exit with.
 * @opcode: toggel for freeing the memory held by the opcode itself.
 */
void free_exit(int file, int stack, int arg, int opcode, int _exit)
{
	if (file)
		fclose(opcode_info.file);
	if (stack)
		free_stack_t(*(opcode_info.stack));
	if (arg)
		free(opcode_info.arg);
	if (opcode)
		free(opcode_info.opcode);
	exit(_exit);
}
