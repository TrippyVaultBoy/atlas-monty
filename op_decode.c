#include "monty.h"

/**
 *
*/

void op_decode(char *ops[], instruction_t instruction[], int instruction_size, stack_t **stack, unsigned int line_number)
{
    int i;

    for (i = 0; i < instruction_size; i++)
    {
        if (strcmp(ops[0], instruction[i].opcode) == 0)
        {
            instruction[i].f(stack, line_number);
            return;
        }
    }

    printf("opcode not found\n");
}
