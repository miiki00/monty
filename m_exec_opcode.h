#ifndef M_EXEC_OPCODE_H
#define M_EXEC_OPCODE_H

int check_opcode(char *opcode);
instruction_t **build_instructions(void);
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number);


#endif
