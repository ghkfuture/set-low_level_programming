#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node to return, starting at 0
 *
 * Return: pointer to the requested node, or NULL if it does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i = 0;

while (head && i < index)
{
head = head->next;
i++;
}

return (head ? head : NULL);
}
