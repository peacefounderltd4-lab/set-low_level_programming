#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to head pointer
 *
 * Return: new head
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev;
	listint_t *curr;
	listint_t *next;

	prev = NULL;
	curr = *head;

	if (head == NULL)
		return (NULL);

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
	return (prev);
}
