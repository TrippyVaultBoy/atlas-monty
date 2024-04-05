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
    FILE *file;
    char line[100];
    char *ops[10];
    int line_number;

    file = fopen("bytecodes/00.m", "r");
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
            printf("%s\n", ops[line_number]);
        }
    }
    fclose(file);
    return (0);
}