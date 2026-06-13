#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

int _putchar(char c);
void print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);
void free_listint2(listint_t **head);

#endif
