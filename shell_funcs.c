#include "s_sh.h"

/**
* _puts - show a string
* @str: string
*/

void _puts(char *str)
{
int i;

i = 0;

while (str[i] != '\0')
{
_puterror(str[i]);
i++;
}
}

/**
* _puterror - writes the character c to stderr
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _puterror(char c)
{
return (write(2, &c, 1));
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
* our_exit - exit
* @str: string from getline.
* Return: Exit Success.
*/

int our_exit(char *str)
{
free(str);
exit(state);
}

/**
* count_delim - count delimiters in str
* @str: string
* @delim: delimiters
* Return: Number of delimiters
*/

int count_delim(char *str, char *delim)
{
int i, k, con = 1;

for (i = 0; str[i]; i++)
{
for (k = 0; delim[k]; k++)
{
if (delim[k] == str[i])
con++;
}
}
return (con);
}
