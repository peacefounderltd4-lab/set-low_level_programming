#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

listint_t *insert_nodeint_at_index(listint_t **head,
				    unsigned int idx, int n);

#endif
