#include "shell.h"
/**
*main - the shell
*Return:int
*/

int main(int argc, char **argv)
{
	char *input;
	char **array;
	int i, x = 0;
	static int j;

	signal(SIGINT, Ctrlc);
	while (1)
	{
		j++;
		x = j;
		input = prompt(argc, argv);
		array = parse(input);
		if (!array)
		{
			free(input);
			break;
		}
		i = execute(argv, array, input, x);
		if (i == 0)
		{
			free(input);
			free(array);
		}
	}
	exit(0);
	return (0);
}

