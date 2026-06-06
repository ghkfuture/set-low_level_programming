#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all data (n) of a dlistint_t list.
 * @head: Root entry node pointing to the chain stack.
 *
 * Return: Consolidated total integer sum, or zero if layout is empty.
 */
int sum_dlistint(dlistint_t *head)
{
int sum = 0;

while (head)
{
sum += head->n;
head = head->next;
}
return (sum);
}
