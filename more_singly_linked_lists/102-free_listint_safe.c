#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees list safely (handles loops)
 * @h: pointer to head pointer
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t count = 0;

	if (h == NULL)
		return (0);

	while (*h != NULL)
	{
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
		count++;
	}

	*h = NULL;
	return (count);
}
