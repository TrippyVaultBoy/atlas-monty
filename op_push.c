#include "monty.h"

/**
 *
*/

void push(stack_t **stack, unsigned int line_number)
{
    int i;

    i = 0;
    printf("push executed\n");
    if (*stack == NULL)
    {
        i = i + line_number;
    }
}
