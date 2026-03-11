#include "main.h"
/**
 * _memset - fills memory with a constant byte
 * @s: memory area to fill
 * @b: constant byte
 * @n: bytes to fill
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
main.h unsigned int i;

main.h for (i = 0; i < n; i++)
main.h main.h s[i] = b;
main.h return (s);
}
