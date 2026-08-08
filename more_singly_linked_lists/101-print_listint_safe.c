#include <stdlib.h>
#include "lists.h"

/**
 * print_hex - prints a number in hexadecimal
 * @number: number to print
 */
static void print_hex(unsigned long number)
{
	char *digits = "0123456789abcdef";

	if (number > 15)
		print_hex(number / 16);

	_putchar(digits[number % 16]);
}

/**
 * print_address - prints an address in hexadecimal
 * @address: address to print
 */
static void print_address(const void *address)
{
	unsigned long number;

	number = (unsigned long)address;

	_putchar('[');
	_putchar('0');
	_putchar('x');

	if (number == 0)
		_putchar('0');
	else
		print_hex(number);

	_putchar(']');
}

/**
 * detect_loop - finds the meeting point of a linked-list loop
 * @head: pointer to the head of the list
 *
 * Return: meeting node, or NULL if there is no loop
 */
static const listint_t *detect_loop(const listint_t *head)
{
	const listint_t *slow;
	const listint_t *fast;

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
 * print_node - prints one list node
 * @node: node to print
 */
static void print_node(const listint_t *node)
{
	print_address((const void *)node);
	_putchar(' ');
	_putchar('0' + (node->n / 1000) % 10);
	_putchar('0' + (node->n / 100) % 10);
	_putchar('0' + (node->n / 10) % 10);
	_putchar('0' + node->n % 10);
	_putchar('\n');
}

/**
 * print_listint_safe - prints a listint_t list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	const listint_t *meeting;
	const listint_t *loop_start;
	size_t count;

	meeting = detect_loop(head);
	current = head;
	count = 0;

	if (meeting == NULL)
	{
		while (current != NULL)
		{
			print_node(current);
			count++;
			current = current->next;
		}
		return (count);
	}

	loop_start = head;
	while (loop_start != meeting)
	{
		loop_start = loop_start->next;
		meeting = meeting->next;
	}

	current = head;
	while (current != loop_start)
	{
		print_node(current);
		count++;
		current = current->next;
	}

	current = loop_start;
	do {
		print_node(current);
		count++;
		current = current->next;
	} while (current != loop_start);

	print_address((const void *)loop_start);
	_putchar(' ');
	_putchar('-');
	_putchar('>');
	_putchar(' ');
	print_address((const void *)loop_start);
	_putchar('\n');

	return (count);
}
