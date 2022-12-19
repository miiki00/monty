#ifndef M_STACK_FUNC_H
#define M_STACK_FUNC_H
/* stack operation related defination and declarations of monty 0.98. */

/* functions declarations */

size_t print_stack_t(const stack_t *h);
stack_t *push_stack_elt(stack_t **head, const int n);
int delete_elt_at_index(stack_t **head, unsigned int index);
size_t stack_len(const stack_t *h);
stack_t *get_elt_at_index(stack_t *head, unsigned int index);
stack_t *init_stack_elt(int n, stack_t *next, stack_t *prev);
stack_t *add_elt_end(stack_t **head, const int n);

#endif
