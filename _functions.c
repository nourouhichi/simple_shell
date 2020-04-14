#include "shell.h"
/**
 * _strdup - duplicates a string
 * @str: pointer to input
 * Return: Returns a pointer to the duplicated string
 */

char *_strdup(char *str)
{
char *dup;
char *copy;
int len = 0;

	if (str == NULL)
		return (NULL);

	for (copy = str; *copy != '\0'; copy++)
		len++;

	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);

	_strcpy(dup, str);
	return (dup);

}
/**
* _strlen - returns the length of a string.
* @s : variable.
* Return: n.
*/

unsigned int _strlen(char *s)
{
unsigned int i;
for (i = 0 ; s[i] != '\0' ; i++)
{
}
return (i);
}
/**
 * _strcpy - copies a string
 * @dest: pointer to the cipies string
 * @src: pointer to the source
 * Return: return the value of dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; ++i)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 *_strncmp - compares n bytes of tow strings
 *@s:const char
 *@t:const char
 *@num:size_t
 *Return: int
 */
int _strncmp(const char *s, const char *t, size_t num)
{
int x = 0;
for (; num > 0; s++, t++, num--)
if (*s == *t)
x++;
if (x == 4)
return (0);
else
return (-1);
}
