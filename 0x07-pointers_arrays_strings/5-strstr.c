#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: main string
 * @needle: substring
 * Return: pointer or NULL
 */
char *_strstr(char *haystack, char *needle)
{
    int i;

    if (*needle == '\0')
        return (haystack);

    while (*haystack)
    {
        i = 0;

        while (needle[i] && haystack[i] == needle[i])
            i++;

        if (needle[i] == '\0')
            return (haystack);

        haystack++;
    }

    return (0);
}
