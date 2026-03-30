#include "main.h"

/**
 * _strspn - gets length of prefix substring
 * @s: string
 * @accept: accepted chars
 * Return: number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int i = 0;
    int j;
    int found;

    while (s[i])
    {
        found = 0;

        for (j = 0; accept[j]; j++)
        {
            if (s[i] == accept[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
            break;

        i++;
    }

    return (i);
}
