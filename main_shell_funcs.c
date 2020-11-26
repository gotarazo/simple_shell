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

/**
 * write_buf - create a buffer (double pointer)
 * @str: string
 * @delim: delimiters
 * Return: Buffer
 */

char **write_buf(char *str, char *delim)
{
  char *token;
  char **buf;
  int con, j = 0;

  con = count_delim(str, delim);
  buf = malloc(sizeof(char *) * (con + 1));
  token = strtok(str, delim);

  while (token)
    {
      buf[j] = _strdup(token);
      token = strtok(NULL, delim);
      j++;
    }
  buf[j] = NULL;
  return (buf);
}
