#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a node at a given index
 * @head: pointer to the first node
 * @idx: index where the new node is inserted
 * @n: integer stored in the new node
 *
 * Return: address of the new node, or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head,
		unsigned int idx, int n)
{
	listint_t *new;
	listint_t *current;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	current = *head;
	i = 0;

	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
	{
		free(new);
		return (NULL);
	}

	new->next = current->next;
	current->next = new;

	return (new);
}
