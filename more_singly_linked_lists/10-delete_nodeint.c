#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node at a given index
 * @head: pointer to the first node
 * @index: index of the node to delete
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current;
	listint_t *previous;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	previous = NULL;
	i = 0;

	while (current != NULL && i < index)
	{
		previous = current;
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	previous->next = current->next;
	free(current);

	return (1);
}
