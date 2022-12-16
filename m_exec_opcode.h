#ifndef M_EXEC_OPCODE_H
#define M_EXEC_OPCODE_H
/* opcode execution related declarations and definations of monty 0.98 */

/* function declarations */
int check_opcode(char *opcode);
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number);
char *handle_opcode_line(char *line);
int is_comment(char *line);

#endif
