#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list in place
 * @head: double pointer to the first node of the list
 *
 * Return: pointer to the first node of the newly reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL;
listint_t *next = NULL;

if (!head || !*head)
return (NULL);

while (*head)
{
next = (*head)->next;
(*head)->next = prev;
prev = *head;
*head = next;
}

*head = prev;
return (*head);
}
