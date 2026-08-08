#include "lists.h"

/**
 * print_number - prints a signed integer
 * @n: integer to print
 */
static void print_number(int n)
{
	unsigned int number;
	unsigned int divisor;
	char digit;

	if (n < 0)
	{
		_putchar('-');
		number = (unsigned int)(-(n + 1));
		number++;
	}
	else
	{
		number = (unsigned int)n;
	}

	divisor = 1;
	while (number / divisor >= 10)
		divisor *= 10;

	while (divisor > 0)
	{
		digit = (char)('0' + (number / divisor) % 10);
		_putchar(digit);
		divisor /= 10;
	}
}

/**
 * print_hex - prints a pointer value in hexadecimal
 * @ptr: pointer to print
 */
static void print_hex(const listint_t *ptr)
{
	unsigned long value;
	unsigned long divisor;
	char digit;

	value = (unsigned long)ptr;
	_putchar('0');
	_putchar('x');

	if (value == 0)
	{
		_putchar('0');
		return;
	}

	divisor = 1;
	while (value / divisor >= 16)
		divisor *= 16;

	while (divisor > 0)
	{
		digit = (char)((value / divisor) % 16);
		if (digit < 10)
			_putchar((char)('0' + digit));
		else
			_putchar((char)('a' + digit - 10));
		divisor /= 16;
	}
}

/**
 * print_node_safe - prints one node
 * @node: node to print
 */
static void print_node_safe(const listint_t *node)
{
	_putchar('[');
	print_hex(node);
	_putchar(']');
	_putchar(' ');
	print_number(node->n);
	_putchar('\n');
}

/**
 * print_listint_safe - prints a list safely
 * @head: pointer to the first node
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow;
	const listint_t *fast;
	size_t count;

	slow = head;
	fast = head;
	count = 0;

	while (slow != NULL)
	{
		print_node_safe(slow);
		count++;

		slow = slow->next;

		if (fast != NULL && fast->next != NULL)
			fast = fast->next->next;
		else
			fast = NULL;

		if (slow != NULL && slow == fast)
		{
			_putchar('-');
			_putchar('>');
			_putchar(' ');
			print_node_safe(slow);
			return (count);
		}

		if (fast == NULL)
			continue;
	}

	return (count);
}
