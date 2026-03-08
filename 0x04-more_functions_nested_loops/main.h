#include "main.h"
#include <stdio.h>

int main(void)
{
    char c;

    c = 'A';
    printf("%c: %d\n", c, _isupper(c)); /* Output: A: 1 */
    c = 'a';
    printf("%c: %d\n", c, _isupper(c)); /* Output: a: 0 */
    return (0);
}
