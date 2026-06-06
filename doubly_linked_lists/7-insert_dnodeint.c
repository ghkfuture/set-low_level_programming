#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Double handle layout pointer tracking head nodes.
 * @idx: Target numeric insertion point starting at zero.
 * @n: Value metric mapped inside target properties.
 *
 * Return: Address of new allocated reference or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *temp;
unsigned int step = 0;

if (!h)
return (NULL);

if (idx == 0)
return (add_dnodeint(h, n));

temp = *h;
while (temp && step < (idx - 1))
{
temp = temp->next;
step++;
}

if (!temp)
return (NULL);

if (!temp->next)
return (add_dnodeint_end(h, n));

new_node = malloc(sizeof(dlistint_t));
if (!new_node)
return (NULL);

new_node->n = n;
new_node->next = temp->next;
new_node->prev = temp;
temp->next->prev = new_node;
temp->next = new_node;

return (new_node);
}
