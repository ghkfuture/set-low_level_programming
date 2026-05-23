#include "lists.h"

/**
 * find_loop_count - Counts unique nodes in a looped listint_t list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: Number of unique nodes, or 0 if no loop.
 */
size_t find_loop_count(const listint_t *head)
{
const listint_t *slow = head, *fast = head;
size_t nodes = 0;

while (slow && fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
{
slow = head;
while (slow != fast)
{
nodes++;
slow = slow->next;
fast = fast->next;
}
slow = slow->next;
while (slow != fast)
{
nodes++;
slow = slow->next;
}
return (nodes + 1);
}
}
return (0);
}

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t nodes, index = 0;

nodes = find_loop_count(head);
if (nodes == 0)
{
for (; head; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
return (index);
}

for (index = 0; index < nodes; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
printf("-> [%p] %d\n", (void *)head, head->n);

return (nodes);
}
