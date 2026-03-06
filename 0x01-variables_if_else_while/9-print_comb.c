#include <stdio.h>

/**
 * main - prints combinations of digits
 * Return: 0
 */

int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + '0');

		if (n != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}
