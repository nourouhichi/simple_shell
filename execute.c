#include "shell.h"
/**
 * is_env - checks for built-ins
 * @array: input array
 * @line:input line
 * Return:int
 */
int is_env(char **array, char *line)
{
	int i;

	if ((_strcmp(array[0], "exit") == 0) && array[1] == NULL)
	{
		free(line);
		free(array);
		exit(0);
	}
	if ((_strcmp(array[0], "env") == 0) && (array[1] == NULL))
	{
		i = 0;
		while (environ[i])
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}

		free(line);
		free(array);
		return (0);
	}
	return (1);
}
/**
 * execute - executes the command with the argument
 * @array:input array
 * @line:input line
 * @av:argv
 * @num:number of times the shell was used
 * Return:int
*/
int execute(char **av, char **array, char *line, int num)
{
	pid_t child;
	int status, ar, ret;
	struct stat st;
	char *test;

	ret = is_env(array, line);
	if (ret == 0)
		return (-1);
	if (ret == 1)
	{
		test = path(array);
		child = fork();
		if (child == -1)
		{
			if (test != NULL)
				free(array[0]);
			free(array);
			return (1);
		}
		if (child == 0)
		{
			ar = stat(array[0], &st);
			if (((execve(array[0], array, environ)) == -1) && (ar != 0))
			{
				if (test != NULL)
					free(array[0]);
				nfound(av, num, array[0]);
				free(array);
				free(line);
				exit(127);
				return (1);
			}
		}
		else
		wait(&status);
		if (test != NULL)
			free(array[0]);
	}
	return (0);
}
/**
 * nfound - display not found message
 * @av:argv
 * @num:number of times the shell was used
 * @cmd:array[0]
 */
void nfound(char **av, int num, char *cmd)
{

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	_itoa(num);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

