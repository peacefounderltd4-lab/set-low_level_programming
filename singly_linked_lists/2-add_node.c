#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds node at beginning
 * @head: pointer to head pointer
 * @str: string to add
 *
 * Return: address of new node or NULL
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	while (str[len])
		len++;

	new->len = len;
	new->next = *head;
	*head = new;

	return (new);
}
