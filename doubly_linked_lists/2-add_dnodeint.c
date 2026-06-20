#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - adds node at beginning
 * @head: double pointer to head
 * @n: integer value
 *
 * Return: new node or NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}
