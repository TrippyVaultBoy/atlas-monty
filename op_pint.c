#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number + 1);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}