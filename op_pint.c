#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
    int i;

    i = 0;
    i = i + line_number;
    if (*stack == NULL)
    {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}