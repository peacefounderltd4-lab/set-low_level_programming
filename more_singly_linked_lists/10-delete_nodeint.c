#include <stdlib.h>
#include "lists.h"

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp, *next;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		free(tmp);
		return (1);
	}

	for (i = 0; tmp && i < index - 1; i++)
		tmp = tmp->next;

	if (!tmp || !tmp->next)
		return (-1);

	next = tmp->next->next;
	free(tmp->next);
	tmp->next = next;

	return (1);
}
