#include "s_sh.h"

/**
* _strlen- Returns the length of a string
* @s: String to get the length
* Return: The length
*/

int _strlen(char *s)
{
int length = 0;

while (s[length])
length++;
return (length);
}

/**
* _strcmp- compares 2 strings
* @s1: String 1
* @s2: String 2
* Return: Difference between strings
*/

int _strcmp(char *s1, char *s2)
{
int count;

for (count = 0; (s1[count] == s2[count]) && (s1[count] != '\0'); count++)
;
return (s1[count] - s2[count]);
}

/**
* _strncmp- Checks if @s1 matches @s2 up to @length amount
* @s1: String to be checked against @s2
* @s2: String used to check @s1
* @length:      How many characters to check
* Return: 0 (if @s1 match against @s2) or any other number if not match against
*/

int _strncmp(char *s1, char *s2, int length)
{
while (length-- && *s1++ && *s2++ && (*s1 == *s2))
;
return (length == 0 ? 0 : *s1 - *s2);
}

/**
* _strcpy- copies the string pointed to by src including terminating null byte
* to the buffer pointed to by dest
* @dest: pointer to destination of string
* @src: pointer to source string to copy from
* Return: Pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
int point;

for (point = 0; src[point] != '\0'; point++)
dest[point] = src[point];
dest[point] = '\0';
return (dest);
}

/**
* signal_handler- Catches and handles signals
* @sig_num: Signal trigger (is 2 with Ctr+C)
*/

void signal_handler(int sig_num)
{
if (sig_num)
write(1, "^C\n", 3);
}
