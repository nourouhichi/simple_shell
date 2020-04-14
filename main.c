#include "shell.h"
/**
*main - the shell
*Return:int
*/

int main(void)
{
	char *input;
	char **array;
	int i;

	signal(SIGINT, Ctrlc);
	while (1)
	{
		input = prompt();
		array = parse(input);
		if (!array)
		{
			free(input);
			break;
		}
		i = execute(array, input);
		if (i == 0)
		{
			free(input);
			free(array);
		}
	}
	exit(0);
	return (0);
}

