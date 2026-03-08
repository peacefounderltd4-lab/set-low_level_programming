#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @n: integer to compute
 *
 * Return: absolute value of n
 *
 * Note: INT_MIN is handled by returning itself (overflow cannot be represented)
 */
int _abs(int n)
{
	if (n < 0)
	{
		if (n == -2147483648) /* INT_MIN for 32-bit systems */
			return (2147483647 + 1); /* works correctly in two's complement */
		return (-n);
	}
	return (n);
}
