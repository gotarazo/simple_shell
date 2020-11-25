#include "s_sh.h"

/**
* custom_atoi- Convert a character-represented number into an integer
* @status: Flag representing whether character is a number or not
* @s: String
* Return: Converted integer
*/

int custom_atoi(int *status, char *s)
{
int i = 0, sum = 0, mul = 1;

while (s[i])
i++;

while (i--)
{
if (s[i] > 57 || s[i] < 48)
*status = 1;

sum += (s[i] - 48) * mul;
mul *= 10;
}
return (sum);
}

/**
* print_env- Pint the environment list
* @env: Array of pointers to environmental variables
* Return: 0
*/

int print_env(char **env)
{
int i = 0;

while (env[i])
{
write(STDOUT_FILENO, env[i], _strlen(env[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
return (0);
}

/**
* run_shell- Check if  getline fails
* @go: Return value of getline function
* Return: 0 (if success) or 1 (if failure)
*/

int run_shell(int go)
{
if (go == -1)
{
write(STDIN_FILENO, "\n", 1);
return (1);
}
return (0);
}

/**
* var_finder- Find the PATH variable in environment list
* @var: String literal of desired environmental variable
* @env: Environment list
* Return: String of desired environment variable and its value
*/

char *var_finder(char *var, char **env)
{
int i = 0, ii = 0;

if (!(var) || !(env))
return (NULL);

while (env[ii] != NULL)
{
i = 0;
while (var[i] != '\0' && var[i] == env[ii][i])
i++;

if (var[i] == '\0')
return (env[ii]);

ii++;
}
return (NULL);
}

/**
* forking_helper- Fork to create child process and execute command
* @av: Commandline argument
* Return: 0 (if success) or 1 (if fail)
*/

int forking_helper(char **av)
{
pid_t forking_val;

forking_val = fork();
if (forking_val == -1)
return (1);

if (forking_val == 0)
{
if (execve(av[0], av, NULL) == -1)
exit(1);
}
else
{
wait(NULL);
return (0);
}
return (0);
}
