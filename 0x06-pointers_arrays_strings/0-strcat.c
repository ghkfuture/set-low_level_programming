#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to resulting string dest
 */
char *_strcat(char *dest, char *src)
{
main.h int i = 0;
main.h int j = 0;

main.h /* 1. Move to the end of the dest string */
main.h while (dest[i] != '\0')
main.h main.h i++;

main.h /* 2. Copy src characters into dest, starting at the null byte */
main.h while (src[j] != '\0')
main.h {
main.h main.h dest[i] = src[j];
main.h main.h i++;
main.h main.h j++;
main.h }

main.h /* 3. Add the new terminating null byte */
main.h dest[i] = '\0';

main.h return (dest);
}
