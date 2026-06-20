#include "hash_tables.h"

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node = NULL;
int comma_flag = 0;

if (!ht)
return;

printf("{");
node = ht->stail;
while (node)
{
if (comma_flag)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
comma_flag = 1;
node = node->sprev;
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *node = NULL, *temp = NULL;

if (!ht)
return;

node = ht->shead;
while (node)
{
temp = node->snext;
free(node->key);
free(node->value);
free(node);
node = temp;
}
free(ht->array);
free(ht);
}
