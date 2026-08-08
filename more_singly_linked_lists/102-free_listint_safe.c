#include <stdlib.h>
#include "lists.h"

/**
 * find_loop_node - finds the meeting point of a loop
 * @head: pointer to the head of the list
 *
 * Return: meeting node, or NULL
 */
static listint_t *find_loop_node(listint_t *head)
{
	listint_t *slow;
	listint_t *fast;

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (slow);
	}

	return (NULL);
}

/**
 * break_loop - breaks a loop in a linked list
 * @head: head of the list
 * @meeting: meeting node
 */
static void break_loop(listint_t *head, listint_t *meeting)
{
	listint_t *start;
	listint_t *last;

	start = head;

	while (start != meeting)
	{
		start = start->next;
		meeting = meeting->next;
	}

	last = start;
	while (last->next != start)
		last = last->next;

	last->next = NULL;
}

/**
 * free_listint_safe - frees a list safely
 * @h: pointer to the head of the list
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current;
	listint_t *next;
	listint_t *meeting;
	size_t count;

	if (h == NULL || *h == NULL)
		return (0);

	meeting = find_loop_node(*h);
	if (meeting != NULL)
		break_loop(*h, meeting);

	current = *h;
	count = 0;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		count++;
	}

	*h = NULL;

	return (count);
}
