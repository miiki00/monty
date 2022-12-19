#ifndef M_ERROR_H
#define M_ERROR_H
/* Error related definations and declaration of monty 0.98 */

/* Error message number(codes) */
	/* LEVEL ONE ERROR CODES */
#define _MONTY_USAGE_ERR 101
#define _MONTY_UNABLE_TO_READ_FILE 102
#define _MONTY_MALLOC_FAILED 103
#define _MONTY_

	/* LEVEL TWO ERROR CODES */
#define _MONTY_PUSH_USAGE 111
#define _MONTY_PINT_STACK_EMPTY 112
#define _MONTY_POP_EMPTY_STACK 113
#define _MONTY_SWAP_STACK_TOO_SHORT 114
#define _MONTY_ADD_STACK_TOO_SHORT 115
#define _MONTY_SUB_STACK_TOO_SHORT 116
#define _MONTY_DIV_STACK_TOO_SHORT 117
#define _MONTY_DIVISION_BY_ZERO 118
#define _MONTY_UNKNOWN_INSTRUCTION 119
#define _MONTY_PCHAR_STACK_EMPTY 120
#define _MONTY_PCHAR_VALUE_OUT_OF_RANGE 121
#define _MONTY_MUL_STACK_TOO_SHORT 122
#define _MONTY_MOD_STACK_TOO_SHORT 123


/* function declarations */
void exit_error_msg(int code, char *add);
void free_exit(int _exit);
void level_one_error(int code, char *add);
void level_two_error(int code, char *add);

#endif
