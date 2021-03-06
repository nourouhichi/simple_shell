#include "shell.h"
/**
* *_strcat - concatenates two strings.
* @dest : destination.
* @src : source.
* Return: a pointer to the resulting string dest.
*/

char *_strcat(char *dest, const char *src)
{
size_t dest_len = _strlen(dest);
size_t i;
for (i = 0 ; src[i] != '\0' ; i++)
dest[dest_len + i] = src[i];
dest[dest_len + i] = '\0';
return (dest);
}

/**
* _strcmp - compares two strings.
* @s1 : string 1.
* @s2 : string 2.
* Return: integer.
*/

int _strcmp(char *s1, char *s2)
{
int i;
i = 0;
while (s1[i] == s2[i])
{
if (s1[i] == '\0' && s2[i] == '\0')
break;
i++;
}
return (s1[i] - s2[i]);
}
/**
 *_itoa - converts an int into a string
 *@num:the integer
 */
void _itoa(int num)
{
if (num / 10 != 0)
{
_itoa(num / 10);
_putchar((num % 10) + '0');
}
else if ((num / 10 == 0) && (num % 10 != 0))
_putchar((num % 10) + '0');
}

