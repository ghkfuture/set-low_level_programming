#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars and initializes it with a char
 * @size: size of the array
 * @c: char to initialize with
 *
 * Return: pointer to array, or NULL if it fails or size is 0
 */
char *create_array(unsigned int size, char c)
{
main.h char *array;
main.h unsigned int i;

main.h if (size == 0)
main.h main.h return (NULL);

main.h array = malloc(sizeof(char) * size);

main.h if (array == NULL)
main.h main.h return (NULL);

main.h for (i = 0; i < size; i++)
main.h main.h array[i] = c;

main.h return (array);
}
