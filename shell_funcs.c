#include "s_sh.h"

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

/**
 * chk_builtin - Verify built in functions
 * @word: string to compare
 * Return: 1 on success, 0 if fail
 */

int chk_builtin(char *word)
{
  int i = 0;

  builtin func_built[] = {
    {"exit", our_exit},
    {"env", _printenv},
    {NULL, NULL}
  };
  if (chk_void(word) == 0)
    return (1);
  while (func_built[i].str != NULL)
    {
      if (my_strcmp(word, func_built[i].str, _strlen(word) - 1) == 0)
	{
	  func_built[i].fun(word);
	  return (1);
	}
      i++;
    }
  return (0);
}

/**
 * chk_path - check if the first argument is a file inside de PATH directories
 * @str: string from getline
 * Return: A Buffer or Array (Double pointer).
 */

char **chk_path(char *str)
{
  int i;
  char *envpath = "PATH=", *concat, *pget;
  char **pbuf, **array;
  struct stat st;

  array = write_buf(str, " \n");

  if (array[0][0] == '.' && array[0][1] == '/')
    return (array);

  pget = (cleanpath(_getenv(envpath)));

  if (pget)
    {
      pbuf = write_buf(pget, ":\n");
      for (i = 0; pbuf[i]; i++)
	{
	  concat = str_concat(pbuf[i], array[0]);

	  if (stat(concat, &st) == 0)
	    {
	      for (i = 0; pbuf[i]; i++)
		free(pbuf[i]);
	      free(pbuf);
	      free(pget);
	      free(array[0]);
	      array[0] = concat;
	      return (array);
	    }
	  free(concat);
	}
      for (i = 0; pbuf[i]; i++)
	free(pbuf[i]);
      free(pbuf);
    }
  free(pget);
  return (array);
}

/**
 * cleanpath - make a copy from de PATH and verify if start with ':'
 * @pathenv: enviroment variable PATH.
 * Return: a string with the final copy of PATH.
 */

char *cleanpath(char *pathenv)
{
  int i, j = 0;
  char *clnpath;

  if (pathenv == NULL)
    return (NULL);
  /* 5 - 1 (PATH= - .) = 4*/
  clnpath = malloc(sizeof(char) * _strlen(pathenv) - 4);

  if (pathenv[5] == ':')
    clnpath[j++] = '.';

  for (i = 5; pathenv[i]; j++, i++)
    {
      clnpath[j] = pathenv[i];
    }
  clnpath[j] = '\0';
  return (clnpath);
}
