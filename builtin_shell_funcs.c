#include "s_sh.h"

/**
* error_no_such - error when no such file or directory
* @str: string.
* @hist: historial of commands
*/

void error_no_such(char *str, int hist)
{
char *ps = ": ";
char *nf = "not found\n";

_puts(sh_call);
_puts(ps);
int_to_str(hist);
_puts(ps);
_puts(str);
_puts(ps);
_puts(nf);
state = 127;
}

/**
* error_permission - error when permissions denied.
* @str: string.
* @hist: historial of commands
*/

void error_permission(char *str, int hist)
{
char *ps = ": ";
char *pd = "Permission denied\n";

_puts(sh_call);
_puts(ps);
int_to_str(hist);
_puts(ps);
_puts(str);
_puts(ps);
_puts(pd);
state = 126;
}

/**
* chk_error - check error.
* @str: string.
* @hist: historial of commands
*/

void chk_error(char *str, int hist)
{
int i;

i = _strlen(str);
str[i] = '\0';

if (errno == ENOENT)
error_no_such(str, hist);
else if (errno == EACCES)
error_permission(str, hist);
}

/**
* _getenv - get a enviroment variable if match.
* @name: name of the enviroment variable.
* Return: enviroment variable, or Null if fail.
*/

char *_getenv(char *name)
{
int i, len = 0;

while (name[len])
len++;

if (environ == NULL)
return (NULL);

for (i = 0; environ[i]; i++)
if ((my_strcmp(environ[i], name, len) == 0))
if (_strlen(environ[i]) > 5)
return (environ[i]);
return (NULL);
}

/**
* _printenv - print env
* @str: string from getline.
* Return: 1 on success, 0 if fail.
*/

int _printenv(char *str)
{
int i, j;

if (!str)
return (0);

for (i = 0; environ[i]; i++)
{
for (j = 0; environ[i][j]; j++)
{
_putchar(environ[i][j]);
}
_putchar(10);
}
return (1);
}
