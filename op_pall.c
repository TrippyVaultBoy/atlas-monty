#include "monty.h"

/**
 *
*/

void pall(stack_t **stack, unsigned int line_number)
{
    if (line_number == 1000)
    {
        return;
    }
    if (*stack == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
