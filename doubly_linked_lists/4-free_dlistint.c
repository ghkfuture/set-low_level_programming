#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: Root pointer to the memory structure block.
 */
void free_dlistint(dlistint_t *head)
{
dlistint_t *next_node;

while (head)
{
next_node = head->next;
free(head);
head = next_node;
}
}
