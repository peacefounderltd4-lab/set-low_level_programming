#include "lists.h"

/**
 * get_dnodeint_at_index - gets node at index
 * @head: head of list
 * @index: index starting from 0
 *
 * Return: pointer to node or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head)
	{
		if (i == index)
			return (head);

		i++;
		head = head->next;
	}

	return (NULL);
}
