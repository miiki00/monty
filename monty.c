#include "monty.h"

/* contains information about the current opcode being executed. */
opcode_i opcode_info;

/**
 * main - entry of the monty interpreter 0.98.
 * @ac: number of command line arguments passed.
 * @av: the actual arguments list(array).
 *
 * Return: EXIT_SUCCESS (success), EXIT_FAILURE (error).
 */
int main(int ac, char **av)
{
	char *line = NULL, *opcode = NULL;
	unsigned int line_number = 1;
	size_t len;
	FILE *_file = NULL;
	stack_t *stack = NULL;

	op_stack(NULL, 0); /* setting default mode to stack */
	check_main_args(ac, av);
	opcode_info.file = _file = open_file(av[1], "rb");
	opcode_info.stack = &stack;
	for (line_number = 1; ; line_number++)
	{
		opcode_info.line_number = line_number;
		if ((getline(&line, &len, _file)) == -1)
		{
			if (line != NULL)
				free(line);
			break;
		}
		opcode_info.opcode = opcode = handle_opcode_line(line);
		if (opcode == NULL)
		{
			line = NULL;
			continue;
		}
		execute_opcode(&stack, opcode, line_number);
		line = NULL;
	}
	free_exit(EXIT_SUCCESS);
	exit(EXIT_SUCCESS);
}

/**
 * check_main_args - checks if valid argument number and valid argument
 * is passed to main.
 * @ac: number arguments.
 * @av: the actual arguments.
 *
 * Return: if returns back to main (valid), else exit.
 */
void check_main_args(int ac, char **av)
{
	FILE *_file;

	if (ac == 2)
		_file = open_file(av[1], "rb");
	else
		exit_error_msg(_MONTY_USAGE_ERR, NULL);
	fclose(_file);
}

/**
 * open_file - open a file and return FILE * to the file.
 * @path: The path to the file.
 * @flags: The flages to open the file with.
 *
 * Return: If it returns a FILE * to the file (success),
 * else it will exit the program.
 */
FILE *open_file(char *path, char *flags)
{
	FILE *_file = NULL;

	_file = fopen(path, flags);
	if (_file == NULL)
		exit_error_msg(_MONTY_UNABLE_TO_READ_FILE, path);
	return (_file);
}
