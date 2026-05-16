#include "lists.h"

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i = 0;

while (head && i < index)
{
head = head->next;
i++;
}

return (head ? (listint_t *)head : NULL);
}
