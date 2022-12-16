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
	int low = 64, high = 91, i, neg;

	if (str == NULL || tog < 1 || tog > 3)
		return (-1);
	if (tog == 2)
	{
		low = 96;
		high = 123;
	}
	else if (tog == 3)
	{
		neg = (*str == '-');
		low = 47;
		high = 58;
	}
	for (i = 0; str[i] != '\0'; i++)
		if (!(str[i] > low && str[i] < high) && !(neg && i == 0))
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
