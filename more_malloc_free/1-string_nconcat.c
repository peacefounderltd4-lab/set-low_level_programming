#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2
 *
 * Return: pointer to new string or NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *res;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 != NULL)
		while (s1[len1])
			len1++;

	if (s2 != NULL)
		while (s2[len2])
			len2++;

	if (n >= len2)
		n = len2;

	res = malloc(len1 + n + 1);
	if (res == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		res[i] = s1[i];

	for (j = 0; j < n; j++)
		res[i + j] = s2[j];

	res[len1 + n] = '\0';

	return (res);
}
