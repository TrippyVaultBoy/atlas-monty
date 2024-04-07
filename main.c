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
    
    instruction_size = 3;
    i = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        tokenize(ops, line);

        /* search through tokenized input */
        for (line_number = 0; ops[line_number] != NULL; line_number++)
        {
            /* search through instructions */
            for (i = 0; i < instruction_size; i++)
            {
                /* compare token to each instruction */
                if (strcmp(ops[line_number], instruction[i].opcode) == 0)
                {
                    /* check if instruction is push */
                    if (strcmp(ops[line_number], "push") == 0)
                    {
                        char *arg = ops[line_number + 1];
                        arg = strtok(arg, "$");

                        /* check if the arg after push is a digit */
                        if (!isdigit(*arg))
                        {
                            fprintf(stderr, "L4: usage: push integer\n");
                            exit(EXIT_FAILURE);
                        }

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
    return (1);
}