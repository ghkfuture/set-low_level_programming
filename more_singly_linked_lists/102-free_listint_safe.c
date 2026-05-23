#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely (handles loops).
 * @h: A double pointer to the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
listint_t **list = NULL, **new_list;
listint_t *next;
size_t i, count = 0;

if (!h || !*h)
return (0);

while (*h)
{
for (i = 0; i < count; i++)
{
if (*h == list[i])
{
*h = NULL;
free(list);
return (count);
}
}
new_list = malloc((count + 1) * sizeof(listint_t *));
if (!new_list)
{
free(list);
exit(98);
}
for (i = 0; i < count; i++)
new_list[i] = list[i];
new_list[count] = *h;
free(list);
list = new_list;
next = (*h)->next;
free(*h);
*h = next;
count++;
}
free(list);
return (count);
}
