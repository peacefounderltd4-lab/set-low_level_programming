#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

int add_to_sorted_list(shash_table_t *ht, shash_node_t *node);
shash_node_t *create_shash_node(const char *key, const char *value);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the created hash table, or NULL if it fails.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * create_shash_node - Dynamically allocates space for a new sorted node.
 * @key: The key string.
 * @value: The value string.
 *
 * Return: A pointer to the new node, or NULL if allocation fails.
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (!node)
		return (NULL);

	node->key = strdup(key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	return (node);
}

/**
 * shash_table_set - Adds or updates an element in a sorted hash table.
 * @ht: The sorted hash table structure.
 * @key: The key string (cannot be empty).
 * @value: The value string associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *curr, *new_node;
	char *new_value;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];
	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
		{
			new_value = strdup(value);
			if (!new_value)
				return (0);
			free(curr->value);
			curr->value = new_value;
			return (1);
		}
		curr = curr->next;
	}

	new_node = create_shash_node(key, value);
	if (!new_node)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (add_to_sorted_list(ht, new_node));
}

/**
 * add_to_sorted_list - Inserts a node into the sorted doubly linked list.
 * @ht: The sorted hash table structure.
 * @node: The pre-allocated node to insert.
 *
 * Return: 1 on success, 0 on failure.
 */
int add_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *curr;

	if (!ht->shead)
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead = node;
		ht->stail = node;
		return (1);
	}
	curr = ht->shead;
	while (curr && strcmp(curr->key, node->key) < 0)
		curr = curr->snext;

	if (!curr)
	{
		node->sprev = ht->stail;
		node->snext = NULL;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else if (curr == ht->shead)
	{
		node->sprev = NULL;
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else
	{
		node->sprev = curr->sprev;
		node->snext = curr;
		curr->sprev->snext = node;
		curr->sprev = node;
	}
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key from sorted table.
 * @ht: A pointer to the sorted hash table structure.
 * @key: The key string to search for.
 *
 * Return: The value associated with the element, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *curr;

	if (!ht || !key || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];
	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
			return (curr->value);
		curr = curr->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table using the sorted list.
 * @ht: A pointer to the sorted hash table structure.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *curr;
	int first = 1;

	if (!ht)
		return;

	printf("{");
	curr = ht->shead;
	while (curr)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		first = 0;
		curr = curr->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table structure.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr;
	int first = 1;

	if (!ht)
		return;

	printf("{");
	curr = ht->stail;
	while (curr)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		first = 0;
		curr = curr->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and frees all memory.
 * @ht: A pointer to the sorted hash table structure.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr, *tmp;

	if (!ht)
		return;

	curr = ht->shead;
	while (curr)
	{
		tmp = curr->snext;
		free(curr->key);
		free(curr->value);
		free(curr);
		curr = tmp;
	}
	free(ht->array);
	free(ht);
}
