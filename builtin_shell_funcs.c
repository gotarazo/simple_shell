#include "s_sh.h"

/**
 * _execve - execute.
 * @ag: commands.
 * @hist: historial of commands.
 * @str: line.
 * Return: Status
 */

void _execve(char **ag, int hist, char *str)
{
  pid_t child_pid;
  int status, i = 0;

  child_pid = fork();

  if (child_pid == 0)
    if (execve(ag[0], ag, environ) == -1)
      {
	chk_error(ag[0], hist);
	free(str);
	while (ag[i])
	  {
	    free(ag[i]);
	    i++;
	  }
	free(ag);
	exit(state);
      }
  if (child_pid > 0)
    {
      wait(&status);
      if (WIFEXITED(status))
	state = WEXITSTATUS(status);
    }
  else
    {
      perror("Error child");
      state = EXIT_FAILURE;
    }
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
