#ifndef S_SH_H
#define S_SH_H

#define BUFFER_SIZE 64

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>

extern char **environ;

/**
* struct builtin- Data type for our list of builtins
* @name: Name of command
* @function: Function pointer of associated name
*/

typedef struct builtin
{
char *name;
int (*function)(char **);
} builtin_t;


/* Main Functions */
void s_sh_loop(int argc, char *argv[]);
char *s_sh_getline(void);
char **s_sh_tokenize(char *line);
int s_sh_execute(char **args, char *line);
int s_sh_launch(char **args, char **dirs, char *line);
void s_sh_search_path(char **args, char **dirs);
void check_environ(char *path, char temp[], char **dirs);

/* Builtin Functions */
int s_sh_help(char **args);
int s_sh_exit(char **args);
int s_sh_error(char **args);
int s_sh_env(char **args);
int s_sh_setenv(char **args);
int s_sh_unsetenv(char **args);
int s_sh_cd(char **args);

/* Basic Functions */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int length);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
void signal_handler(int sig_num);
char *cmdcat(char *dir, char *file);

#endif
