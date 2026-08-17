#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: Size of the hash table
 *
 * Return: Pointer to the created hash table, or NULL on failure
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
 * shash_create_node - Creates a sorted hash node
 * @key: Key
 * @value: Value
 *
 * Return: Pointer to new node, or NULL on failure
 */
shash_node_t *shash_create_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	return (node);
}

/**
 * shash_insert_sorted - Inserts a node in sorted order
 * @ht: Sorted hash table
 * @node: Node to insert
 *
 * Return: 1
 */
int shash_insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return (1);
	}

	current = ht->shead;

	while (current != NULL && strcmp(current->key, node->key) < 0)
		current = current->snext;

	if (current == ht->shead)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
		return (1);
	}

	if (current == NULL)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
		return (1);
	}

	node->sprev = current->sprev;
	node->snext = current;
	current->sprev->snext = node;
	current->sprev = node;

	return (1);
}

/**
 * shash_table_set - Adds or updates an element
 * @ht: Sorted hash table
 * @key: Key
 * @value: Value
 *
 * Return: 1 if successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *current;
	shash_node_t *node;
	char *new_value;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
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

	node = shash_create_node(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	return (shash_insert_sorted(ht, node));
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: Sorted hash table
 * @key: Key
 *
 * Return: Value associated with key, or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
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
 * shash_table_print - Prints the sorted hash table
 * @ht: Sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	int first;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->shead;
	first = 1;

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
 * shash_table_print_rev - Prints the sorted hash table in reverse
 * @ht: Sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	int first;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->stail;
	first = 1;

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
 * shash_table_delete - Deletes the sorted hash table
 * @ht: Sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current;
	shash_node_t *next;

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

	free(ht->array);
	free(ht);
}
