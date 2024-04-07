#include "monty.h"

/**
 * tokenize- tokenizes the input string into an array
 * @array: array for the tokens to be stored
 * @command: input string of commands to be tokenized
*/
void tokenize(char *array[], char *command)
{
    char *token;
    int i;

    token = strtok(command, " ");
    i = 0;

	while (token != NULL)
	{
		if (token[strlen(token) - 1] == '\n')
		{
			token[strlen(token) - 1] = '\0';
		}
		array[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	array[i] = NULL;

}