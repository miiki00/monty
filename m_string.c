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
