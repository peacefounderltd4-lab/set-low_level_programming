#include "main.h"

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to new string or NULL
 */
char *_strdup(char *str)
{
	char *copy;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];

	copy[len] = '\0';

	return (copy);
}
