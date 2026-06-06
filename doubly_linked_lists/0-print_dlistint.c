#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: Head pointer of the doubly linked list.
 *
 * Return: The total number of nodes traversed.
 */
size_t print_dlistint(const dlistint_t *h)
{
lists.h size_t nodes = 0;

lists.h while (h)
lists.h {
lists.h lists.h printf("%d\n", h->n);
lists.h lists.h nodes++;
lists.h lists.h h = h->next;
lists.h }
lists.h return (nodes);
}
