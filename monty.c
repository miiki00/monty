#include "monty.h"

/* global variable argument fron montybyte code */
char *G_arg;

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

	check_main_args(ac, av);
	_file = open_file(av[1], "r");
	for (line_number = 1; ; line_number++)
	{
		if ((getline(&line, &len, _file)) == -1)
			break;
		printf("line %d: %s", line_number, line);
		opcode = handle_line(line);
		if (opcode == NULL)
		{
			line = NULL;
			continue;
		}
		execute_opcode(&stack, opcode, line_number);
		line = NULL;
	}
	fclose(_file);
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
		_file = open_file(av[1], "r");
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

/**
 * handle_line - extracts the neccessary information from a line of
 * montybyte code.
 * @line: the line to analayz.
 *
 * Return: opcode if the line contains a valid opcode.
 * else if blank line NULL.
 * else prints the right error message and exit.
 */
char *handle_line(char *line)
{
	char *token = NULL, *opcode = NULL, *tmp = NULL;
	char *delimeters = " \t\n";
	int ret;

	if (line == NULL)
		return (NULL);

	token = strtok(line, delimeters);
	if (token == NULL)
	{
		free(line);
		return (NULL);
	}
	ret = check_opcode(token);
	if (ret == -1)
		exit_error_msg(101, NULL); /* needs fixing */
	if (ret == 1)
	{
		tmp = strtok(NULL, delimeters);
		if(tmp != NULL)
			G_arg = strdup(tmp);
		else
			G_arg == NULL;
	}
	opcode = strdup(token);
	free(line);
	return (opcode);
}

