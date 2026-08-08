```c
#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current;
	listint_t *previous;

	if (head == NULL || *head == NULL)
		return (NULL);

	current = *head;
	previous = NULL;

	while (current != NULL)
	{
		*head = current->next;
		current->next = previous;
		previous = current;
		current = *head;
	}

	*head = previous;

	return (*head);
}
```
