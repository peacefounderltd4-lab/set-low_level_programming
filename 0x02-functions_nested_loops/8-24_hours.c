#include "main.h"

/**
 * jack_bauer - prints every minute of the day
 *
 * Return: void
 */
void jack_bauer(void)
{
	int h, m;

	for (h = 0; h < 24; h++)       /* loop through hours */
	{
		for (m = 0; m < 60; m++)   /* loop through minutes */
		{
			_putchar('0' + h / 10); /* tens of hour */
			_putchar('0' + h % 10); /* units of hour */
			_putchar(':');
			_putchar('0' + m / 10); /* tens of minute */
			_putchar('0' + m % 10); /* units of minute */
			_putchar('\n');
		}
	}
}
