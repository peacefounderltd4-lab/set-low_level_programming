char *_strstr(char *haystack, char *needle)
{
    int i, j;

    if (*needle == '\0')
        return (haystack);

    for (i = 0; haystack[i]; i++)
    {
        for (j = 0; needle[j] && haystack[i + j] == needle[j]; j++)
            ;

        if (!needle[j])
            return (&haystack[i]);
    }

    return (0);
}
