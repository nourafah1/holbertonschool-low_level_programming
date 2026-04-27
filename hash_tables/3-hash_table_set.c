#include "hash_tables.h"
#include <string.h>

/**
 * update_value - updates value if key exists
 * @node: node list
 * @key: key
 * @value: new value
 *
 * Return: 1 if updated, 0 if not found
 */
int update_value(hash_node_t *node, const char *key, const char *value)
{
	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
		node = node->next;
	}
	return (0);
}

/**
 * hash_table_set - adds element to hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	if (update_value(ht->array[index], key, value))
		return (1);

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (0);

	new->key = strdup(key);
	new->value = strdup(value);

	if (new->key == NULL || new->value == NULL)
	{
		free(new->key);
		free(new->value);
		free(new);
		return (0);
	}

	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
