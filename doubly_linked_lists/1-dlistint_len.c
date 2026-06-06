#include "lists.h"

/**
 * dlistint_len - Calculates the number of elements in a dlistint_t list.
 * @h: Head pointer of the doubly linked list.
 *
 * Return: Count of elements present.
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t nodes = 0;

while (h)
{
nodes++;
h = h->next;
}
return (nodes);
}
