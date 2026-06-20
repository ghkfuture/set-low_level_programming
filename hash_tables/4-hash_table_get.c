#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: A pointer to the hash table.
 * @key: The key string to search for.
 * Return: The value associated with the element, or NULL if not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int index;
hash_node_t *curr = NULL;

if (!ht || !key || *key == '\0')
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
curr = ht->array[index];

while (curr)
{
if (strcmp(curr->key, key) == 0)
return (curr->value);
curr = curr->next;
}

return (NULL);
}
