#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - retrieves value by key
 * @ht: hash table
 * @key: key to search
 *
 * Return: value or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->next;
	}

	return (NULL);
}
