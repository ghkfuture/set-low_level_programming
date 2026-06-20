#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 * Return: A pointer to the table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht = NULL;
unsigned long int i;

if (size == 0)
return (NULL);

ht = malloc(sizeof(shash_table_t));
if (!ht)
return (NULL);

ht->array = malloc(sizeof(shash_node_t *) * size);
if (!ht->array)
{
free(ht);
return (NULL);
}

for (i = 0; i < size; i++)
ht->array[i] = NULL;

ht->size = size;
ht->shead = NULL;
ht->stail = NULL;

return (ht);
}

/**
 * insert_sorted_node - Inserts a node into the sorted list.
 * @ht: The sorted hash table.
 * @node: The node to insert.
 */
void insert_sorted_node(shash_table_t *ht, shash_node_t *node)
{
shash_node_t *curr = ht->shead;

if (!ht->shead)
{
ht->shead = node;
ht->stail = node;
node->sprev = NULL;
node->snext = NULL;
return;
}
while (curr && strcmp(node->key, curr->key) > 0)
curr = curr->snext;
if (!curr)
{
node->sprev = ht->stail;
node->snext = NULL;
ht->stail->snext = node;
ht->stail = node;
}
else if (curr == ht->shead)
{
node->snext = ht->shead;
node->sprev = NULL;
ht->shead->sprev = node;
ht->shead = node;
}
else
{
node->snext = curr;
node->sprev = curr->sprev;
curr->sprev->snext = node;
curr->sprev = node;
}
}

/**
 * shash_table_set - Sets a key-value pair in a sorted table.
 * @ht: The sorted hash table.
 * @key: The key string.
 * @value: The value string.
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
shash_node_t *curr = NULL, *new = NULL;
char *new_val = NULL;

if (!ht || !key || *key == '\0' || !value)
return (0);
index = key_index((const unsigned char *)key, ht->size);
curr = ht->array[index];
while (curr)
{
if (strcmp(curr->key, key) == 0)
{
new_val = strdup(value);
if (!new_val)
return (0);
free(curr->value);
curr->value = new_val;
return (1);
}
curr = curr->next;
}
new = malloc(sizeof(shash_node_t));
if (!new)
return (0);
new->key = strdup(key);
new->value = strdup(value);
if (!new->key || !new->value)
{
free(new->key);
free(new->value);
free(new);
return (0);
}
new->next = ht->array[index];
ht->array[index] = new;
insert_sorted_node(ht, new);
return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key.
 * @ht: The sorted hash table.
 * @key: The key string.
 * Return: The value string, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int index;
shash_node_t *curr = NULL;

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

/**
 * shash_table_print - Prints a sorted hash table using the sorted list.
 * @ht: The sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node = NULL;
int comma_flag = 0;

if (!ht)
return;

printf("{");
node = ht->shead;
while (node)
{
if (comma_flag)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
comma_flag = 1;
node = node->snext;
}
printf("}\n");
}
