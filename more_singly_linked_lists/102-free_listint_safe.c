#include "lists.h"

/**
 * count_loop_nodes - Counts unique nodes in a looped listint_t list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: Number of unique nodes, or 0 if no loop.
 */
size_t count_loop_nodes(listint_t *head)
{
listint_t *slow = head, *fast = head;
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
 * free_listint_safe - Frees a listint_t list safely (handles loops).
 * @h: A double pointer to the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
size_t nodes, index = 0;
listint_t *temp;

if (!h || !*h)
return (0);

nodes = count_loop_nodes(*h);
if (nodes == 0)
{
while (*h)
{
temp = (*h)->next;
free(*h);
*h = temp;
index++;
}
*h = NULL;
return (index);
}

for (index = 0; index < nodes; index++)
{
temp = (*h)->next;
free(*h);
*h = temp;
}
*h = NULL;
return (nodes);
}
