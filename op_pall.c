#include "monty.h"

/**
 *
*/

void pall(stack_t **stack, unsigned int line_number)
{
    int i;

    i = 0;
    printf("pall executed\n");
    if (*stack == NULL)
    {
        i = i + line_number;
    }
}
