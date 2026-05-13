#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to new string or NULL
 */
char *str_concat(char *s1, char *s2)
{
	char *res;
	int i, j, len1 = 0, len2 = 0;

	if (s1 != NULL)
		while (s1[len1])
			len1++;

	if (s2 != NULL)
		while (s2[len2])
			len2++;

	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		res[i] = s1[i];

	for (j = 0; j < len2; j++)
		res[i + j] = s2[j];

	res[len1 + len2] = '\0';

	return (res);
}
