#include <stdio.h>
/**
 *
*/

int main()
{
    FILE *file;
    char line[100];

    file = fopen("bytecodes/00.m", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (1);
    }

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
    return (0);
}