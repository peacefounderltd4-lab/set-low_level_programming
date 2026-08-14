#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the table
 *
 * Return: pointer to the table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - adds a key/value pair
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;
	shash_node_t *tmp;
	char *new_value;

	if (ht == NULL || key == NULL || value == NULL || key[0] == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);

			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (0);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (0);
	}

	node->next = ht->array[index];
	node->sprev = NULL;
	node->snext = NULL;
	ht->array[index] = node;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return (1);
	}

	tmp = ht->shead;

	while (tmp != NULL && strcmp(key, tmp->key) > 0)
		tmp = tmp->snext;

	if (tmp == NULL)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else
	{
		node->snext = tmp;
		node->sprev = tmp->sprev;

		if (tmp->sprev != NULL)
			tmp->sprev->snext = node;
		else
			ht->shead = node;

		tmp->sprev = node;
	}

	return (1);
}

/**
 * shash_table_get - retrieves a value
 * @ht: hash table
 * @key: key
 *
 * Return: value or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || key[0] == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints the hash table
 * @ht: hash table
 *
 * Return: nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");

	node = ht->shead;

	while (node != NULL)
	{
		if (!first)
			printf(", ");

		printf("'%s': '%s'", node->key, node->value);
		first = 0;
		node = node->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints the hash table in reverse
 * @ht: hash table
 *
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");

	node = ht->stail;

	while (node != NULL)
	{
		if (!first)
			printf(", ");

		printf("'%s': '%s'", node->key, node->value);
		first = 0;
		node = node->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes the hash table
 * @ht: hash table
 *
 * Return: nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node;
	shash_node_t *next;
	unsigned long int i;

	if (ht == NULL)
		return;

	node = ht->shead;

	while (node != NULL)
	{
		next = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = next;
	}

	for (i = 0; i < ht->size; i++)
		ht->array[i] = NULL;

	free(ht->array);
	free(ht);
}
