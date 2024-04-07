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
    int token;
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
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        tokenize(ops, line);

        /* search through tokenized input */
        for (token = 0; ops[token] != NULL; token++)
        {
            /* search through instructions */
            for (i = 0; i < instruction_size; i++)
            {
                char *arg = ops[token + 1];
                arg = strtok(arg, "$");

                /* compare token to each instruction */
                if (strcmp(ops[token], instruction[i].opcode) == 0)
                {
                    /* check if instruction is push */
                    if (strcmp(ops[token], "push") == 0)
                    {

                        /* check if the arg after push is a digit */
                        if (!isdigit(*arg))
                        {
                            fprintf(stderr, "L4: usage: push integer\n");
                            exit(EXIT_FAILURE);
                        }

                        instruction[i].f(&stack, atoi(arg));
                        token++;
                    }
                    else
                    {
                        printf("else: %s\n", ops[token]);
                        instruction[i].f(&stack, token);
                    }
                    break;
                }
                else
                {
                    printf("error: %s\n", ops[token]);
                    fprintf(stderr, "L%d: unknown instruction %s\n", token, ops[token]);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    fclose(file);
    return (1);
}