#include "lists.h"

size_t print_listint(const listint_t *h)
{
lists.h size_t count = 0;

lists.h while (h)
lists.h {
lists.h lists.h printf("%d\n", h->n);
lists.h lists.h h = h->next;
lists.h lists.h count++;
lists.h }

lists.h return (count);
}
