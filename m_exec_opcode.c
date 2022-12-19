#include "monty.h"

/**
 * check_opcode - checks if opcode takes argument or not or if
 * it even exists.
 * @opcode: the opcode to check.
 *
 * Return: 1 (opcode takes argument), 0 (opcode doesn't take arguments),
 * -1 (opcode doesn't exist), 2 for comment.
 */
int check_opcode(char *opcode)
{
	int i;
	char *arg_opcodes[] = {
		"push", NULL
	};
	char *nonarg_opcodes[] = {
		"pall", "pint", "pop", "swap",
		"add", "nop", "sub", "div",
		"mul", "mod", "pchar", "pstr",
		"rotl", "rotr", "stack", "queue",
		NULL
	};

	if (opcode == NULL)
		return (0);
	if (is_comment(opcode))
		return (2);
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
		{"push", &op_push}, {"pall", &op_pall}, {"pint", &op_pint},
		{"pop", &op_pop}, {"swap", &op_swap}, {"add", &op_add},
		{"nop", &op_nop}, {"sub", &op_sub}, {"div", &op_div},
		{"mul", &op_mul}, {"mod", &op_mod}, {"pchar", &op_pchar},
		{"pstr", &op_pstr}, {"rotl", &op_rotl}, {"rotr", &op_rotr},
		{"stack", &op_stack}, {"queue", &op_queue}
	};
	int i;

	for (i = 0; i < OPCODES_N; i++)
	{
		if (exact_match(opcode, (instructions[i]).opcode))
		{
			free(opcode);
			opcode_info.opcode = NULL;
			(instructions[i]).f(stack, line_number);
			break;
		}
	}
}

/**
 * handle_opcode_line - extracts the neccessary information from a line of
 * montybyte code.
 * @line: the line to analayz.
 *
 * Return: opcode if the line contains a valid opcode.
 * else if blank line NULL.
 * else prints the right error message and exit.
 */
char *handle_opcode_line(char *line)
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
	{
		opcode_info.opcode = _strdup(token);
		free(line); /* needs fixing */
		exit_error_msg(_MONTY_UNKNOWN_INSTRUCTION, opcode_info.opcode);
	}
	if (ret == 1)
	{
		tmp = strtok(NULL, delimeters);
		if (tmp != NULL)
			opcode_info.arg = _strdup(tmp);
		else
			opcode_info.arg = NULL;
	}
	if (ret == 2)
	{
		free(line);
		return (NULL);
	}
	opcode = _strdup(token);
	free(line);
	return (opcode);
}

/**
 * is_comment - checks if a given line is a comment or not.
 * @line: The line to check.
 *
 * Return: 1 (comment), 0 (not).
 */
int is_comment(char *line)
{
	if (line == NULL)
		return (0);
	if (*line == '#')
		return (1);
	return (0);
}
