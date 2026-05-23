#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: pointer to the first node of the list
 *
 * Return: total sum of data fields, or 0 if list is empty
 */
int sum_listint(listint_t *head)
{
int total = 0;

while (head)
{
total += head->n;
head = head->next;
}

return (total);
}
