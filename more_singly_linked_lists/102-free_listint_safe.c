#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a linked list safely
 * @h: pointer to the list head
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *start;
	listint_t *current;
	listint_t *next;
	size_t count;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	if (fast != NULL && fast->next != NULL && slow == fast)
	{
		slow = *h;

		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}

		start = slow;
		current = start;

		while (current->next != start)
			current = current->next;

		current->next = NULL;
	}

	count = 0;
	current = *h;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		count++;
		current = next;
	}

	*h = NULL;

	return (count);
}
