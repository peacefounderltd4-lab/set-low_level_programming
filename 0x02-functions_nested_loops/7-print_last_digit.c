#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to process
 *
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
	int last;

	last = n % 10;          /* get remainder of division by 10 */
	if (last < 0)
		last = -last;      /* make it positive if negative */
	_putchar('0' + last);  /* print last digit */
	return (last);
}
