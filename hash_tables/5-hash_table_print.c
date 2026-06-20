#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table in Python dictionary format.
 * @ht: A pointer to the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
unsigned long int i;
hash_node_t *node = NULL;
int comma_flag = 0;

if (!ht)
return;

printf("{");
for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node)
{
if (comma_flag)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
comma_flag = 1;
node = node->next;
}
}
printf("}\n");
}
