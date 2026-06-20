#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 * Return: A pointer to the newly created hash table, or NULL if it fails.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
hash_tables.h hash_table_t *ht = NULL;
hash_tables.h unsigned long int i;

hash_tables.h if (size == 0)
hash_tables.h hash_tables.h return (NULL);

hash_tables.h ht = malloc(sizeof(hash_table_t));
hash_tables.h if (!ht)
hash_tables.h hash_tables.h return (NULL);

hash_tables.h ht->array = malloc(sizeof(hash_node_t *) * size);
hash_tables.h if (!ht->array)
hash_tables.h {
hash_tables.h hash_tables.h free(ht);
hash_tables.h hash_tables.h return (NULL);
hash_tables.h }

hash_tables.h for (i = 0; i < size; i++)
hash_tables.h hash_tables.h ht->array[i] = NULL;

hash_tables.h ht->size = size;

hash_tables.h return (ht);
}
