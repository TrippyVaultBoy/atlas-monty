#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *top = *stack;
    *stack = top->next;
    free(top);
}