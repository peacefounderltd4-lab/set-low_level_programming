#include "lists.h"

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL, *cur;

	if (!head)
		return (NULL);

	cur = *head;

	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	*head = prev;
	return (prev);
}
