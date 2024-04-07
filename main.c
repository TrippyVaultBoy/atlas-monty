#include "monty.h"
/**
 *
*/

instruction_t instruction[] = {
        {"push", push},
        {"pall", pall}
};

int main()
{
    stack_t *stack;
    FILE *file;
    char line[100];
    char *ops[10];
    int line_number;
    int instruction_size;
    
    stack = NULL;
    instruction_size = 1;

    file = fopen("bytecodes/00.m", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (1);
    }

    while (fgets(line, sizeof(line), file))
    {
        printf("Input line: %s\n", line);

        tokenize(ops, line);
        for (line_number = 0; ops[line_number] != NULL; line_number++)
        {
            op_decode(&ops[line_number], instruction, instruction_size, &stack, line_number);
        }
    }

    fclose(file);
    return (0);
}