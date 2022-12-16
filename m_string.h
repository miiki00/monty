#ifndef M_STRING_H
#define M_STRING_H
/* string related declarations and defination of monty 0.98 */

/* macros for is_tog function tog parameter */
#define _IS_UPPER 1
#define _IS_LOWWER 2
#define _IS_NUMBER 3

/* function declarations */
int exact_match(char *a, char *b);
int is_tog(char *str, int tog);
char *_strdup(char *str);

#endif
