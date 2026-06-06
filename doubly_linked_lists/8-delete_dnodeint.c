#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a list.
 * @head: Double structural tracking handle pointing to list entry.
 * @index: Precise targeted structural index coordinate offset.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp;
unsigned int step = 0;

if (!head || !*head)
return (-1);

temp = *head;
if (index == 0)
{
*head = temp->next;
if (*head)
(*head)->prev = NULL;
free(temp);
return (1);
}

while (temp && step < index)
{
temp = temp->next;
step++;
}

if (!temp)
return (-1);

temp->prev->next = temp->next;
if (temp->next)
temp->next->prev = temp->prev;

free(temp);
return (1);
}
