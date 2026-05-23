#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list handling cyclic loops safely
 * @h: double pointer to the head node of the target list
 *
 * Return: total size of the nodes cleared from memory
 */
size_t free_listint_safe(listint_t **h)
{
size_t nodes = 0;
long int diff;
listint_t *temp;

if (!h || !*h)
return (0);

while (*h)
{
diff = *h - (*h)->next;
if (diff > 0)
{
temp = (*h)->next;
free(*h);
*h = temp;
nodes++;
}
else
{
free(*h);
*h = NULL;
nodes++;
break;
}
}
*h = NULL;
return (nodes);
}
