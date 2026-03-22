#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
    int i;
    int cap;

    i = 0;
    cap = 1;
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
