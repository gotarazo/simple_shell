#include "s_sh.h"

/**
* main- Entry point for the Simple Shell
* @argc: Argument counter
* @argv: Pointer to array of strings
* Return: 0
*/

int main(int argc, char *argv[])
{
signal(SIGINT, signal_handler);
s_sh_loop(argc, argv);
return (0);
}

/**
* s_sh_loop- Loop of the Simple Shell
* @argc: Number of args
* @argv: Pointer to string array
*/

void s_sh_loop(int argc, char *argv[])
{
char *line = NULL, **tokens;
int status = 1;
(void) argc;
(void) argv;
do {
line = s_sh_getline();
tokens = s_sh_tokenize(line);
status = s_sh_execute(tokens, line);
free(line);
free(tokens);
} while (status);
}

/**
* s_sh_execute- Search builtins for function to execute & send to s_sh_launch
* @args: Pointer to list of arguments
* @line: String holding path
* Return: 1 (if success)
*/

int s_sh_execute(char **args, char *line)
{
int i = 0, size = 0;
char temp[150], *path = NULL, **dirs;

builtin_t builtins[] = {
{"help", s_sh_help}, {"exit", s_sh_exit},
{"env", s_sh_env}, {"cd", s_sh_cd},
{"setenv", s_sh_setenv}, {"unsetenv", s_sh_unsetenv},
{"", s_sh_error}
};
dirs = malloc(sizeof(char *) * BUFFER_SIZE);
if (!dirs)
{
write(1, "Malloc error in execute\n", 24);
exit(101);
}
size = (sizeof(builtins) / (sizeof(char *) * 2));
if (args[0] == '\0')
{
free(dirs);
return (1);
}
for (i = 0; i < size; i++)
{
if (_strcmp(args[0], builtins[i].name) == 0)
{
/* Running found matching builtin */
free(path);
free(dirs);
return (builtins[i].function(args));
}
}
/* No matching builtins, search for program in path */
check_environ(path, temp, dirs);
free(path);
/* No builtins found, search path and run matching executable */
s_sh_launch(args, dirs, line);
free(dirs);
return (1);
}
