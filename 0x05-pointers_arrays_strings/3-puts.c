#include "main.h"

void _puts(char *str)
{
    int i = 0;

    if (str == NULL)
        return;

    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }
    _putchar('\n');
}
