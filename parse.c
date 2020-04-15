#include "shell.h"
/**
* parse - parses the input and puts it in an array null terminated
* @line: user input
* Return: the array
*/
char **parse(char *line)
{
	char **array;
	char *token;
	int i = 0;

	array = malloc(sizeof(char *) * 1024);
	if (array == NULL)
	{
		perror(*array);
		free(line);
		free(array);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\a\r\n");
	if (token == NULL)
	{
		free(array);
		free(line);
		perror(token);
		return (NULL);
	}
	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, " \t\a\r\n");
		i++;
	}
	/*array[i] = token;*/
	i++;
	array[i] = NULL;
	return (array);
	}

