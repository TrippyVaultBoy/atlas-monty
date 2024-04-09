#include "monty.h"

void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}