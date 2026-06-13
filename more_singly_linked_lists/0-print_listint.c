#include <stdio.h>
#include "lists.h"

void print_listint(const listint_t *h)
{
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
