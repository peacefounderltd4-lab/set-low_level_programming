#include "lists.h"

/**
 * get_nodeint_at_index - returns nth node
 * @head: pointer to list
 * @index: node index starting at 0
 *
 * Return: pointer to node or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head != NULL)
	{
		if (count == index)
			return (head);

		head = head->next;
		count++;
	}

	return (NULL);
}
