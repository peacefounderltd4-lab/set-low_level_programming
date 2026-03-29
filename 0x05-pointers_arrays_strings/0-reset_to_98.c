#include "main.h"
#include <stddef.h>  /* For NULL */

/**
 * reset_to_98 - updates the value of an integer to 98
 * @n: pointer to the integer to be updated
 */
void reset_to_98(int *n)
{
    if (n != NULL)
        *n = 98;
}
