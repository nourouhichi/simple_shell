#include "shell.h"
/**
 * path- checks if the simple command exists
 * @array:the user input in an array
 * Return: the path to the command if success and null if failure
 */
char *path(char **array)
{
	int i = 0, x;
	struct stat st;
	char *_path, *path_str, *path;

	while (environ[i]) /*get the variable PATH from env*/
	{
		if (_strncmp(environ[i], "PATH", 4) == 0)
			break;
		i++;
	}
	path = _strdup(environ[i]);
	path_str = strtok(path, "=");	/*remove the word PATH= from the string*/
	path_str = strtok(NULL, ":");
	while (path_str != NULL)	/*try paths with the command*/
	{
		x = (_strlen(path_str) + _strlen(array[0]));
		_path = malloc(sizeof(char) * x + 2);
		if (!_path)
		{
			write(STDIN_FILENO, "Error assign memory\n", 50);
			free(_path);
			free(path);
			return (NULL);
		}
		_path = _strcpy(_path, path_str);
		_strcat(_path, "/");	/*add the char/ to the path so it is executable*/
		_strcat(_path, array[0]);/*add the command*/
		if (stat(_path, &st) == 0)/*check if the command exists*/
		{
			array[0] = _strdup(_path);
			free(path);
			free(_path);
			return (array[0]);
					/*if success return the command concatinated with the path*/
		}
		free(_path);
		path_str = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

