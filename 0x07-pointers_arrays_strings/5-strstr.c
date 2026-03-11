#include "main.h"
#include <stddef.h>
/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring to find
 * Return: pointer to beginning of substring, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
for (; *haystack != '\0'; haystack++)
{
char *h = haystack;
char *n = needle;

while (*h == *n && *n != '\0')
{
h++;
n++;
}
if (*n == '\0')
return (haystack);
}
return (NULL);
}
