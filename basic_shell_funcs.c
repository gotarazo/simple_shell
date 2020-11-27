#include "s_sh.h"

/**
* _strdup - duplicates
* @str: string to copy
* Return: Null if size 0 or if not memory available
*/

char *_strdup(char *str)
{
unsigned int i = 0, j;
char *p;

if (str == NULL)
return (NULL);
/* primero asigno el tamaño de memoria con Malloc */

while (str[i] != 0)
i++;

p = malloc(i + 1);

if (p == NULL)
return (NULL);

for (j = 0; str[j] != 0; j++)
p[j] = str[j];

p[j] = '\0';
return (p);
}

/**
* str_concat - concatenate 2 str
* @s1: string 1
* @s2: string 2
* Return: Null if size 0
*/

char *str_concat(char *s1, char *s2)
{
unsigned int i, j, l, l1 = 0, l2 = 0;
char *p;

/* primero asigno el tamaño de memoria con Malloc */

if (s1 != NULL)
{
while (s1[l1] != 0)
l1++;
}
if (s2 != NULL)
{
while (s2[l2] != 0)
l2++;
}
l = l1 + l2 + 2;

p = malloc(sizeof(char) * l);

if (p == NULL)
return (NULL);

for (i = 0; i < l1; i++)
p[i] = s1[i];
p[i++] = '/';
for (j = 0; j < l2; j++)
p[i + j] = s2[j];
p[i + j] = 0;

return (p);
}

/**
* _strlen - size of array
* @s: string
* Return: len
*/
int _strlen(char *s)
{
int i = 0;

while (s[i])
i++;

return (i);
}

/**
* chk_void - chekck if the string is void.
* @env: string 1.
* Return: -1 if the strings are diferents, in the other case, 0.
*/

int chk_void(char *env)
{
int j = 0;

if (env[0] == ' ' || env[0] == '\t')
while (env[j] == ' ')
j++;
if (env[j] == '\n' && env[j + 1] == '\0')
return (0);
return (-1);
}

/**
* my_strcmp - compare two strings.
* @env: string 1.
* @str: string 2.
* @len: chars to compare.
* Return: -1 if the strings are diferents, in the other case, 0.
*/

int my_strcmp(char *env, const char *str, int len)
{
int j;

for (j = 0; j < len; j++)
{
if (env[j] != str[j])
return (-1);
}
return (0);
}
