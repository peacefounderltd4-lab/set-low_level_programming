#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - Entry point to validate basic sorted hash table creation.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	shash_table_t *ht;

	ht = shash_table_create(1024);
	if (ht == NULL)
	{
		return (EXIT_FAILURE);
	}
	shash_table_set(ht, "Betty", "Cool");
	shash_table_print(ht);
	shash_table_delete(ht);

	return (EXIT_SUCCESS);
}
