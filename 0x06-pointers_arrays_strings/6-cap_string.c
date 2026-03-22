#include "main.h"

/**
 * cap_string - capitalize words
 */
char *cap_string(char *str)
{
    int i = 0;
    int cap = 1;

    while (str[i])
    {
        if (cap && str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
            cap = 0;
        }

        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
            str[i] == ',' || str[i] == ';' || str[i] == '.' ||
            str[i] == '!' || str[i] == '?' || str[i] == '"' ||
            str[i] == '(' || str[i] == ')' || str[i] == '{' ||
            str[i] == '}')
        {
            cap = 1;
        }

        i++;
    }

    return (str);
}
