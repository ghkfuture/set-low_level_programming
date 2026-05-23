#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at a specified index
 * @head: double pointer to the first node of the list
 * @index: index of the node that should be deleted, starting at 0
 *
 * Return: 1 if operation succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *temp, *current = *head;
unsigned int i = 0;

if (!head || !*head)
return (-1);

if (index == 0)
{
*head = (*head)->next;
free(current);
return (1);
}

while (current && i < (index - 1))
{
current = current->next;
i++;
}

if (!current || !(current->next))
return (-1);

temp = current->next;
current->next = temp->next;
free(temp);

return (1);
}
