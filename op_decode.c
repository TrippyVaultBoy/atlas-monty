#include "monty.h"

/**
 *
*/

void op_decode(char *ops[], instruction_t instruction[], stack_t **stack, unsigned int line_number)
{
    int i;

    for (i = 0; i < sizeof(instruction)/sizeof(instruction[0]); i++)
    {
        if (strcmp(ops[0], instruction[i].opcode) == 0)
        {
            instruction[i].f(stack, line_number);
            return;
        }
    }

    printf("opcode not found");
    return;
}
