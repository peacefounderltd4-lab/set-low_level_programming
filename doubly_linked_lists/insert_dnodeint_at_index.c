#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: pointer to head
 * @idx: index to insert at (0-based)
 * @n: value to store in new node
 *
 * Return: address of new node, or NULL if failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h,
unsigned int idx, int n)
{
	dlistint_t *new_node, *tmp;
	unsigned int i = 0;

	if (!h)
		return (NULL);

	/* insert at head */
	if (idx == 0)
		return (add_dnodeint(h, n));

	tmp = *h;

	/* move to node before target position */
	while (tmp && i < idx - 1)
	{
		tmp = tmp->next;
		i++;
	}

	/* index out of range */
	if (!tmp)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;

	new_node->next = tmp->next;
	new_node->prev = tmp;

	/* fix next node if it exists */
	if (tmp->next)
		tmp->next->prev = new_node;

	tmp->next = new_node;

	return (new_node);
}
