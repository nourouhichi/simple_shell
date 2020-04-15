#include"shell.h"
/**
 * stroc - counts the occurrence of a character in a string
 * @input: the string to be parsed
 * @c:the character to cout its occurence
 * Return: occurence
 */
unsigned int stroc(char *input, char c)
{
	int i;
	unsigned int j = 0;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == c)
			j++;
	}
	return (j);
}
/**
 * prompt - displays the shell and gets the user input
 * @ac:argc
 * @av:argv
 * Return: returns user input
 */
char *prompt(int ac, char **av)
{
	char *input;
	size_t size = 0;
	ssize_t getinput;

	input = NULL;
	if (isatty(STDIN_FILENO) == 1)
		write(STDIN_FILENO, "$ ", 2);		/*display message to the user*/
	getinput = getline(&input, &size, stdin);
	if (getinput == -1)
	{
		write(STDIN_FILENO, "\n", 1);
		free(input);
		exit(0);
	}
	input[getinput - 1] = '\0';
	if ((_strcmp(input, "\0") == 0) || (stroc(input, ' ') == _strlen(input)))
	{
		free(input);
		main(ac, av);
	/*if the user enter space or enter display the prompt again*/
	}
	return (input);
}

