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
* *_strdup- Returns a pointer to a newly allocated space in memory
* which contains a copy of the string given as a parameter
* @str: String
* Return: Pointer to the duplicated string or NULL (if str NULL)
*/

char *_strdup(char *str)
{
char *c;
int i, n;

if (str == NULL)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
;
i++;
c = malloc(i *sizeof(*c));
if (c == NULL)
return (NULL);
for (n = 0; n < i; n++)
c[n] = str[n];
return (c);
}

/**
* _itoa- Convert an integer to char
* @num: Number to be converted
* Return: String of numbers
*/

char *_itoa(int num)
{
char *str;
int i = 0, num_copy = num;

while (num_copy > 0)
{
num_copy /= 10;
i++;
}
str = malloc(sizeof(char) * (i + 1));
if (str == NULL)
return (NULL);

str[i] = '\0';
while (i--)
{
str[i] = (num % 10) + '0';
num /= 10;
}
return (str);
}

/**
* free_array- Free tokens in array and the array itself
* @array: Array of pointers to tokens
*/

void free_array(char **array)
{
int i = 0;

if (array == NULL)
return;

while (array[i])
{
free(array[i]);
i++;
}
free(array);
}
