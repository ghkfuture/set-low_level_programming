#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Root node anchor pointer.
 * @index: Position marker starting at offset zero.
 *
 * Return: Reference to target node address location, or NULL if missing.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int step = 0;

while (head && step < index)
{
head = head->next;
step++;
}

return (head);
}
