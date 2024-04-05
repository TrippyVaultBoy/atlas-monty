#include "monty.h"
/**
 *
*/

int main()
{
    FILE *file;
    char line[100];
    char *ops[10];
    int i;

    file = fopen("bytecodes/00.m", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (1);
    }

    while (fgets(line, sizeof(line), file))
    {
        tokenize(ops, line);
        for (i = 0; ops[i] != NULL; i++)
        {
            printf("%s\n", ops[i]);
        }
    }
    fclose(file);
    return (0);
}