#include <stdlib.h>
#include "lists.h"

size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t count = 0;

	if (!h)
		return (0);

	while (*h)
	{
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
		count++;
	}

	*h = NULL;
	return (count);
}
