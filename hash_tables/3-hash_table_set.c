#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * create_node - Creates a new hash node with duplicated key and value.
 * @key: The key string.
 * @value: The value string.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (NULL);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

/**
 * hash_table_set - Adds or updates an element in a hash table.
 * @ht: The hash table to add or update the key/value to.
 * @key: The key string (cannot be empty).
 * @value: The value string associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *curr, *new_node;
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

	new_node = create_node(key, value);
	if (!new_node)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
