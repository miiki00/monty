#ifndef M_ERROR_H
#define M_ERROR_H

/* Error message number(codes) */
#define _MONTY_USAGE_ERR 101
#define _MONTY_UNABLE_TO_READ_FILE 102
/* #define _MONTY_UNKNOWN_INSTRUCTION 103 */
#define _MONTY_MALLOC_FAILED 103

/* Error related local functions */
void exit_error_msg(int code, char *add);

#endif
