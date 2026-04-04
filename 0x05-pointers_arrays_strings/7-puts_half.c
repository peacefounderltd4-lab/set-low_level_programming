#include "main.h"

/**
 * puts_half - prints second half of string
 * @str: input string
 */
void puts_half(char *str)
{
	int len = 0, start, i;

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	for (i = start; str[i] != '\0'; i++)
		_putchar(str[i]);

	_putchar('\n');
}
