#include <cstring>
#include <stdlib.h>
#include <stdio.h>

/**
* _strlen - returns the length of a string.
* @s : variable.
* Return: n.
*/

int _strlen(char *s)
{
int n = 0;
int i;
for (i = 0 ; s[i] != 0 ; i++)
{
n++;
}
return (n);
}

/**
* _puts - prints a string.
* @str : string
* Return: void.
*/

void _puts(char *str)
{
int i;
for (i = 0 ; str[i] != 0 ; i++)
{
_putchar(str[i]);
}
_putchar('\n');
}

/**
* *_strcpy - copies a string to another string.
* @dest : destination.
* @src : source.
* Return: char value.
*/

char *_strcpy(char *s, char *x)
{
int i;
int l;
l = 0;

while ((*(src + l) != '\0'))
l++;

for (i = 0 ; i <= l ; i++)
{
dest[i] = src[i];
}
return (&dest[0]);
}

/**
* *_strcat - concatenates two strings.
* @dest : destination.
* @src : source.
* Return: a pointer to the resulting string dest.
*/

char *_strcat(char *dest, char *src)
{
int i;
int l;
int k;
char *p;
l = 0;
for (i = 0 ; dest[i] != 0 ; i++)
l++;
k = 0;
for (k = 0 ; src[k] != 0 ; k++)
k++;
for (i = 0 ; i <= k ; i++)
{
dest[l + i] = src[i];
}
p = dest;
return (p);
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
