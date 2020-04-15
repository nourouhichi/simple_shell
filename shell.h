#ifndef SHELL
#define SHELL
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
extern char **environ;
char **parse(char *line);
char *prompt(int argc, char **argv);
int execute(char **av, char **array, char *str, int num);
int  main(int argc, char **argv);
int is_env(char **array, char *str);
void Ctrlc(int x);
char *path(char **array);
unsigned int stroc(char *input, char c);
unsigned int _strlen(char *s);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, const char *src);
int _strncmp(const char *s, const char *t, size_t num);
void nfound(char **av, int num, char *cmd);
int _putchar(char c);
void _itoa(int num);
#endif

