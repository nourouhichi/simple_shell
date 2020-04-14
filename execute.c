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

	if (_strcmp(array[0], "exit") == 0)
	{
		free(line);
		free(array);
		exit(0);
	}
	if ((_strcmp(array[0], "env") == 0))
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
 * Return:int
*/
int execute(char **array, char *line)
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
			perror("fork failed");
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
				perror(array[0]);
				free(array);
				free(line);
				exit(0);
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
