#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list safely (handles loops)
 * @head: pointer to the head node of the list
 *
 * Return: the total number of nodes verified in the list
 */
size_t print_listint_safe(const listint_t *head)
{
size_t nodes = 0;
const listint_t *current = head, *runner;

while (current)
{
printf("[%p] %d\n", (void *)current, current->n);
nodes++;
current = current->next;
runner = head;

while (runner != current)
{
if (runner == current->next)
{
printf("-> [%p] %d\n", (void *)current->next, current->next->n);
return (nodes);
}
runner = runner->next;
}
}
return (nodes);
}
