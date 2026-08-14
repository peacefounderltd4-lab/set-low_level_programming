#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the new hash table, or NULL on failure
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
 * insert_sorted - inserts node in sorted linked list
 * @ht: hash table
 * @node: node to insert
 *
 * Return: nothing
 */
static void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	current = ht->shead;

	while (current != NULL && strcmp(node->key, current->key) > 0)
		current = current->snext;

	if (current == NULL)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else
	{
		node->snext = current;
		node->sprev = current->sprev;

		if (current->sprev != NULL)
			current->sprev->snext = node;
		else
			ht->shead = node;

		current->sprev = node;
	}
}

/**
 * shash_table_set - adds or updates a key/value pair
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
	shash_node_t *current;
	char *new_value;

	if (ht == NULL || key == NULL || value == NULL || key[0] == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);

			free(current->value);
			current->value = new_value;

			return (1);
		}

		current = current->next;
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

	insert_sorted(ht, node);

	return (1);
}

/**
 * shash_table_get - retrieves a value
 * @ht: hash table
 * @key: key
 *
 * Return: value, or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL || key[0] == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);

		current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints the hash table in sorted order
 * @ht: hash table
 *
 * Return: nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");

	current = ht->shead;

	while (current != NULL)
	{
		if (!first)
			printf(", ");

		printf("'%s': '%s'", current->key, current->value);

		first = 0;
		current = current->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints in reverse sorted order
 * @ht: hash table
 *
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");

	current = ht->stail;

	while (current != NULL)
	{
		if (!first)
			printf(", ");

		printf("'%s': '%s'", current->key, current->value);

		first = 0;
		current = current->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: hash table
 *
 * Return: nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current;
	shash_node_t *next;
	unsigned long int i;

	if (ht == NULL)
		return;

	current = ht->shead;

	while (current != NULL)
	{
		next = current->snext;

		free(current->key);
		free(current->value);
		free(current);

		current = next;
	}

	for (i = 0; i < ht->size; i++)
		ht->array[i] = NULL;

	free(ht->array);
	free(ht);
}
