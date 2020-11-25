#include "s_sh.h"
#define DELIM " \t\r\n"

/**
* s_sh_tokenize- Split @line into tokens and store in an array
* @line: User input stored as a string
* Return: Pointer to the string
*/

char **s_sh_tokenize(char *line)
{
char **tokens, *token = NULL;
int i = 0;

tokens = malloc(sizeof(char *) * BUFFER_SIZE);
if (tokens == NULL)
{
write(1, "Failure to allocate\n", 20);
return (NULL);
}
/* Case handling if no user input */
if (line == NULL)
{
tokens[0] = "";
return (tokens);
}
/* Actual user input. Process into array of tokens */
token = strtok(line, DELIM);
while (token != NULL)
{
tokens[i++] = token;
token = strtok(NULL, DELIM);
}
tokens[i] = NULL;
return (tokens);
}

/**
* s_sh_getline- Get the command as one large string
* @void: Without args
* Return: pointer to the string
*/

char *s_sh_getline(void)
{
char *line = NULL;
size_t b_size = 0;
int i = 0, length = 0;
char cwd[128];

getcwd(cwd, sizeof(cwd));
length = _strlen(cwd);
write(1, "(", 1);
write(1, cwd, length);
write(1, ")", 1);
getline(&line, &b_size, stdin);
if (_strcmp(line, "\n") == 0)
{
/* checks condition when enter is pressed */
free(line);
return (NULL);
}
while (line[i])
i++;

if (i <= 1)
{
fflush(stdin);
line = "";
}
return (line);
}

/**
* check_environ- Checks environment variables for command
* @path: Tokenized string of PATH
* @temp: Temporary array to hold characters
* @dirs: Pointer to our array of directories
*/

void check_environ(char *path, char temp[], char **dirs)
{
int i = 0;

while (environ[i])
{
if (_strncmp("PATH=", environ[i], 5) == 0)
{
path = _strcpy(temp, environ[i]);
break;
}
i++;
}
path += 5;
i = 0;
path = strtok(path, ":");
while (path != '\0')
{
dirs[i] = path;
i++;
path = strtok(NULL, ":");
}
dirs[i] = NULL;
}

/**
* s_sh_launch- Find commannd in args and executes
* @args: Pointer to array of arguments
* @dirs: Pointer to array of directories
* @line: String holding path
* Return: status as int from fork
*/

int s_sh_launch(char **args, char **dirs, char *line)
{
int status = 1;
pid_t pid;

pid = fork();
if (pid == 0)
{
/* Given full path to run program */
if (args[0][0] == '/')
{
if (execve(args[0], args, NULL) == -1)
perror("Error launching dir/prog\n");
}
/* Given only program name, search path */
s_sh_search_path(args, dirs);
free(line);
free(args);
free(dirs);
exit(0);
}
else if (pid < 0)
{
perror("Fork error in launcher.\n");
exit(103);
}
else
wait(&status);

return (status);
}

/**
* s_sh_search_path- Search PATH variables for command
* @args: Pointer to array of arguments
* @dirs: Pointer to array of PATH directories
*/

void s_sh_search_path(char **args, char **dirs)
{
char *command = NULL;
DIR *p_dir;
struct dirent *p_file;
int i;

for (i = 0; dirs[i] != '\0'; i++)
{
p_dir = opendir(dirs[i]);
while ((p_file = readdir(p_dir)) != NULL)
{
if (_strcmp(p_file->d_name, args[0]) == 0)
{
command = cmdcat(dirs[i], args[0]);
if (execve(command, args, NULL) == -1)
perror("No program in path\n");
}
}
closedir(p_dir);
}
}
