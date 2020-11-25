#include "s_sh.h"

/**
* s_sh_error- Triggered if user enters no input
* @args: Pointer to array of tokens
* Return: 1
*/

int s_sh_error(char **args)
{
(void) args;
return (1);
}

/**
* s_sh_env- Prints the current environment
* @args: Pointer to array of tokens
* Return: 1 (if success)
*/

int s_sh_env(char **args)
{
int i = 0;
int len = 0;
(void) args;

while (environ[i])
{
len = _strlen(environ[i]);
write(1, environ[i], len);
write(1, "\n", 1);
i++;
}
return (1);
}

/**
* s_sh_help- Displays help
* @args: Pointer to array of tokens
* Return: 1 (if runs)
*/

int s_sh_help(char **args)
{
char *line = "|-------------------------------------------------------|\n";
char *name = "| Name\t\t| Description\t\t\t\t|\n";
char *help = "| help\t\t| This document\t\t\t\t|\n";
char *env = "| env\t\t| Prints out the system environment\t|\n";
char *setenv = "| setenv\t| Usage setenv variable value overwrite |\n";
char *unsetenv = "| unsetenv\t| Usage unsetenv variable \t\t|\n";
char *cd = "| cd \t\t| Changes the current working directory\t|\n";
char *exit = "| exit\t\t| Exit Simple Shell\t\t|\n";
(void) args;

write(1, line, _strlen(line));
write(1, name, _strlen(name));
write(1, line, _strlen(line));
write(1, help, _strlen(help));
write(1, env, _strlen(env));
write(1, setenv, _strlen(setenv));
write(1, unsetenv, _strlen(unsetenv));
write(1, cd, _strlen(cd));
write(1, exit, _strlen(exit));
write(1, line, _strlen(line));
return (1);
}

/**
* s_sh_exit- Function to exit sfsh
* @args: Pointer to array of tokens
* Return: 0
*/

int s_sh_exit(char **args)
{
int i = 0, number = 0;
char *msg = "Leaving Simple Shell\n";
(void) args;

while (args[++i])
;
if (i > 1)
{
for (i = 0; args[1][i] != '\0'; i++)
{
number *= 10;
number += args[1][i] - '0';
}
write(1, msg, _strlen(msg));
free(args);
exit(number);
}
write(1, msg, _strlen(msg));
return (0);
}

/**
* cmdcat- Concatenates @dir and @file into executable format
* @dir: Directory where @file resides
* @file: Program to be executed
* Return: Concatenated string of @dir + / + @file
*/

char *cmdcat(char *dir, char *file)
{
int dir_length = 0, file_length = 0;

while (dir[++dir_length])
;
dir[dir_length++] = '/';

while (file[file_length])
dir[dir_length++] = file[file_length++];

dir[dir_length] = '\0';
return (dir);
}
