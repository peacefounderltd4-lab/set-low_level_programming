#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at given index
 * @head: pointer to head
 * @index: index of node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	tmp = *head;

	/* delete first node */
	if (index == 0)
	{
		*head = tmp->next;
		if (*head)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	/* move to target node */
	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	if (!tmp)
		return (-1);

	/* reconnect links */
	if (tmp->prev)
		tmp->prev->next = tmp->next;

	if (tmp->next)
		tmp->next->prev = tmp->prev;

	free(tmp);

	return (1);
}
