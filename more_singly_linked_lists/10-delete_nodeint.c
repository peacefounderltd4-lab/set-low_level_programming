#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at index of a listint_t list
 * @head: pointer to head pointer
 * @index: index of node to delete (starts at 0)
 *
 * Return: 1 if success, -1 if failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current;
	listint_t *next;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* delete head */
	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	/* go to node before target */
	for (i = 0; current != NULL && i < index - 1; i++)
		current = current->next;

	/* index out of range */
	if (current == NULL || current->next == NULL)
		return (-1);

	next = current->next->next;
	free(current->next);
	current->next = next;

	return (1);
}
