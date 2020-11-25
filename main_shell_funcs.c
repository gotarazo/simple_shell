#include "s_sh.h"

/**
* tokenizer- Parse a string into tokens using delimiters
* @str: String to be parsed
* @delim: Delimiter
* Return: Array of pointers to tokens
*/

char **tokenizer(char *str, const char *delim)
{
int i = 0;
char *str_1 = NULL, *str_2 = NULL, *ptr = NULL, **ar = NULL;

if (!(str) || !(delim))
return (NULL);

str_1 = _strdup(str);
str_2 = _strdup(str);
if (!(str_1) || !(str_2))
return (NULL);

ptr = strtok(str_1, delim);
if (ptr == NULL)
return (NULL);

for (i = 0; ptr != NULL; i++)
ptr = strtok(NULL, delim);

ar = malloc(sizeof(char *) * (i + 1));
if (ar == NULL)
return (NULL);

ptr = strtok(str_2, delim);
if (ptr == NULL)
return (NULL);

for (i = 0; ptr != NULL; i++)
{
ar[i] = _strdup(ptr);
ptr = strtok(NULL, delim);
}
ar[i] = NULL;
free(str_1);
free(str_2);
return (ar);
}

/**
* smart_cat- Append the command to its directory path
* @path: Array of pointers to tokenized path directories
* @name: The command
* Return: Buffer containing concatenated string of the command and its path
*/

char *smart_cat(char **path, char *name)
{
char *buff = NULL;
int i = 0, ii = 0, v = 0;

if (!(path) || !(name))
return (NULL);

if (name[0] == '/')
return (NULL);

while (path[v] != NULL)
{
buff = malloc(sizeof(char) * (_strlen(path[v]) + _strlen(name) + 2));
if (!(buff))
return (NULL);

i = 0;
ii = 0;
while (path[v][ii])
{
buff[i] = path[v][ii];
i++;
ii++;
}
buff[i] = '/';
i++;
ii = 0;
while (name[ii])
{
buff[i] = name[ii];
i++;
ii++;
}
buff[i] = '\0';
if (access(buff, F_OK) == 0)
return (buff);

else
free(buff);

v++;
}
return (NULL);
}

/**
* life- Exits main function, produce appropriate error messages,
* print environment, check if command is executable, fork and execute
* @array: array of pointers to commandline tokens
* @argv: current commandline arguments
* @env: array of environmental variables
* @p_t: array of pointers to tokenized path
* @i: number of calls
* @e_c: exit integer value
* Return: 0 (if success) or 1 (if fails)
*/

int life(char **array, char **argv, char **env, char **p_t, int i, int *e_c)
{
int error = 0;
char *ptr = NULL, *a_call_count = NULL;

if (array != NULL && !(_strcmp(array[0], "exit")))
{
if (array[1] == NULL)
return (1);

*e_c = custom_atoi(&error, array[1]);
if (error)
{
a_call_count = _itoa(i);
ERR_EXIT(argv[0], a_call_count, array[1]);
free(a_call_count);
}
else
return (1);
}
else if (array != NULL && !(_strcmp(array[0], "env")))
print_env(env);

else if (array != NULL && access(array[0], F_OK) == -1)
{
ptr = array[0];
array[0] = smart_cat(p_t, array[0]);
if (array[0] == NULL)
{
array[0] = _strdup("(nil)");
a_call_count = _itoa(i);
ERR_EXE(argv[0], a_call_count, ptr);
free(a_call_count);
}
free(ptr);
}
if (array != NULL && _strcmp(array[0], "(nil)"))
forking_helper(array);

return (0);
}
