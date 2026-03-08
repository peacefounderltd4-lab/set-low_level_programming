#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet in lowercase 10 times
 */
void print_alphabet_x10(void)
{
	int i, j;
	char c;

	for (i = 0; i < 10; i++)
	{
		for (j = 0, c = 'a'; j < 26; j++, c++)
			_putchar(c);
		_putchar('\n');
	}
}
