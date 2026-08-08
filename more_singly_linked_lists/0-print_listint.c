#include "lists.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 */
static void print_number(int n)
{
	unsigned int number;

	if (n < 0)
	{
		_putchar('-');
		number = (unsigned int)(-(n + 1)) + 1;
	}
	else
	{
		number = (unsigned int)n;
	}

	if (number / 10)
		print_number(number / 10);

	_putchar('0' + number % 10);
}

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to the first node
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t count;

	count = 0;

	while (h != NULL)
	{
		print_number(h->n);
		_putchar('\n');
		h = h->next;
		count++;
	}

	return (count);
}
