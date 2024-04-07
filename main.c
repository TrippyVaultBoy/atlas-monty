#include "monty.h"
/**
 *
*/

instruction_t instruction[] = {
        {"push", push},
        {"pall", pall},
        {"pall$", pall}
};

int main(int argc, char **argv)
{
    stack_t *stack = NULL;
    FILE *file;
    char line[100];
    char *ops[10];
    int line_number;
    int instruction_size;
    int i;
    
    instruction_size = 2;
    i = 0;

    if (argc != 2)
    {
        printf("wrong argument count");
        return (1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (1);
    }

    while (fgets(line, sizeof(line), file))
    {
        tokenize(ops, line);
        for (line_number = 0; ops[line_number] != NULL; line_number++)
        {
            for (i = 0; i <= instruction_size; i++)
            {
                if (strcmp(ops[line_number], instruction[i].opcode) == 0)
                {
                    if (strcmp(ops[line_number], "push") == 0)
                    {
                        char *arg = ops[line_number + 1];
                        instruction[i].f(&stack, atoi(arg));
                        line_number++;
                    }
                    else
                    {
                        instruction[i].f(&stack, line_number);
                    }
                    break;
                }
            }
        }
    }

    fclose(file);
    return (0);
}