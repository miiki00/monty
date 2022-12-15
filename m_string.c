#include "monty.h"

/**
 * exact_match - checks if two string are exact match.
 * @a: the first string.
 * @b: the second string.
 *
 * Return: 1 (exact match), 0 (not exact match).
 */
int exact_match(char *a, char *b)
{
	int len_a, len_b, idx;

	len_a = strlen(a);
	len_b = strlen(b);
	if (len_a != len_b)
		return (0);
	for (idx = 0; idx < len_a; idx++)
		if (a[idx] != b[idx])
			return (0);
	return (1);
}

/**
 * handle_line - extracts the neccessary information from a line of
 * montybyte code.
 * @line: the line to analayz.
 * @line_number: for error message in case of failure.
 * @stack: for memory managment in case of failuer.
 * @f: for memory managment in case of failure.
 * Return: opcode if the line contains a valid opcode.
 * else if blank line NULL.
 * else prints the right error message and exit.
 */
char *handle_line(char *line, unsigned int line_num, stack_t *stack, FILE *f)
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
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token);
		free(line); /* needs fixing */
		free_stack_t(stack); /* needs fixing */
		fclose(f); /* needs fixing */
		exit(EXIT_FAILURE);
	}
	if (ret == 1)
	{
		tmp = strtok(NULL, delimeters);
		if (tmp != NULL)
			G_arg = _strdup(tmp);
		else
			G_arg = NULL;
	}
	opcode = _strdup(token);
	free(line);
	return (opcode);
}

/**
 * is_tog - check if a string contains homogenous content based on
 * a given toggels.
 * @str: the string.
 * @tog: 1(_IS_UPPER) to check all char's are upper,
 * 2(_IS_SMALLER) to check if all char's are smaller,
 * 3(_IS_NUMBER) to check if all char's are number,
 *
 * Return: 1 (homogenous), 0 (not homogenous), -1 (invalid argument).
 */
int is_tog(char *str, int tog)
{
	int low = 64, high = 91, i;

	if (str == NULL || tog < 1 || tog > 3)
		return (-1);
	if (tog == 2)
	{
		low = 96;
		high = 123;
	}
	else if (tog == 3)
	{
		low = 47;
		high = 58;
	}
	for (i = 0; str[i] != '\0'; i++)
		if (!(str[i] > low && str[i] < high))
			return (0);
	return (1);
}

/**
 * _strdup - copies and stores a string in a new memory address.
 * @str: The address of the string to be copied.
 *
 * Return: The address of the string if succeed
 * on error NULL.
 */
char *_strdup(char *str)
{
	char *ptr;
	int i, j;

	if (str == NULL)
		return (NULL);
	for (i = 0; *(str + i) != '\0';)
		i++;
	ptr = monty_malloc(sizeof(char) * (i + 1));
	for (j = 0; j <= i; j++)
		*(ptr + j) = *(str + j);
	return (ptr);
}
