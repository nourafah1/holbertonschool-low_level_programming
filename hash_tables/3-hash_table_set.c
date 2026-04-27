#include "hash_tables.h"
#include <string.h>

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
	hash_node_t *new, *tmp;
	unsigned long int index;
	char *val_dup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];

	/* check if key exists */
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}

	/* create new node */
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (0);

	new->key = strdup(key);
	val_dup = strdup(value);

	if (new->key == NULL || val_dup == NULL)
	{
		free(new->key);
		free(val_dup);
		free(new);
		return (0);
	}

	new->value = val_dup;

	/* insert at beginning (collision handling) */
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
