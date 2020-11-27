#ifndef S_SH_H
#define S_SH_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

/**
* struct builtin - lista enlazada individualmente
* @str: string (cadena malloc'ed)
* @fun: apunta al siguiente nodo
* Description: List that contain the a string and a function.
*/

typedef struct builtin
{
char *str;
int (*fun)(char *);
} builtin;

extern char **environ;
char *sh_call;
int state;

/* FUNCTIONS */

void _execve(char **ag, int, char *);
char **write_buf(char *, char *);
char **chk_path(char *);
int my_strcmp(char *env, const char *str, int len);
char *_getenv(char *);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int chk_builtin(char *);
int _strlen(char *s);
int count_delim(char *str, char *delim);
int our_exit(char *);
int _printenv(char *);
int _putchar(char c);
void _puts(char *);
char *cleanpath(char *);
int chk_void(char *);
/* Error */
void chk_error(char *, int);
void error_permission(char *, int);
void error_no_such(char*, int);
void int_to_str(int);
int _puterror(char);

#endif
