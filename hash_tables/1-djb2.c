#include "hash_tables.h"

/**
 * hash_djb2 - Implementation of the djb2 algorithm.
 * @str: The input string to hash.
 * Return: The calculated hash value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash;
int i;

hash = 5381;
for (i = 0; str[i] != '\0'; i++)
{
hash = ((hash << 5) + hash) + str[i];
}
return (hash);
}
