#include "monty.h"
/**
 *
*/

instruction_t instruction[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"nop", nop}
};

int main(int argc, char **argv)
{
    stack_t *stack = NULL;
    FILE *file;
    char line[100];
    char *ops[10];
    int token;
    int instruction_size;
    int instruct_num;
    int line_num;
    int found_op;
    int j;
    
    instruction_size = 5;
    instruct_num = 0;
    line_num = 1;
    found_op = 0;

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
            for (instruct_num = 0; instruct_num < instruction_size; instruct_num++)
            {
                // printf("Token: %s Instruction: %s\n", ops[token], instruction[instruct_num].opcode);
                /* compare token to each instruction */
                if (strcmp(ops[token], instruction[instruct_num].opcode) == 0)
                {
                    found_op = 1;
                    /* check if instruction is push */
                    if (strcmp(ops[token], "push") == 0)
                    {
                        if (ops[token + 1] == NULL)
                        {
                            fprintf(stderr, "L%d: usage: push integer\n", line_num);
                            exit(EXIT_FAILURE);  
                        }

                        char *arg = ops[token + 1];
                        arg = strtok(arg, "\n");
                        if (arg == NULL)
                        {
                            fprintf(stderr, "L%d: usage: push integer\n", line_num);
                            exit(EXIT_FAILURE); 
                        }

                        /* check if the arg after push is a digit */
                        for (j = 0; j < (signed int)strlen(arg); j++)
                        {
                            if (!isdigit(arg[j]))
                            {
                                fprintf(stderr, "L%d: usage: push integer\n", line_num);
                                exit(EXIT_FAILURE); 
                            }
                        }

                        instruction[instruct_num].f(&stack, atoi(arg));
                        break;
                    }
                    else
                    {
                        instruction[instruct_num].f(&stack, line_num - 1);
                    }
                    break;
                }
            }
            if (!found_op)
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_num, ops[0]);
                exit(EXIT_FAILURE);
            }
        }
        found_op = 0;
        line_num = line_num + 1;
    }

    fclose(file);
    free_stack(&stack);
    return (1);
}