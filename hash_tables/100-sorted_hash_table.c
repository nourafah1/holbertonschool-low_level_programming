#include "hash_tables.h"
#include <string.h>
#include <stdio.h>
/**
 * shash_table_create - creates a sorted hash table
 * @size: size of array
 *
 * Return: pointer to hash table or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
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
 * create_node - creates a sorted hash node
 * @key: key
 * @value: value
 *
 * Return: new node or NULL
 */
shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *new;

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (NULL);

	new->key = strdup(key);
	new->value = strdup(value);
	if (new->key == NULL || new->value == NULL)
	{
		free(new->key);
		free(new->value);
		free(new);
		return (NULL);
	}

	new->next = NULL;
	new->sprev = NULL;
	new->snext = NULL;

	return (new);
}

/**
 * update_node - updates node value if key exists
 * @node: node list
 * @key: key
 * @value: value
 *
 * Return: 1 if updated, 0 otherwise
 */
int update_node(shash_node_t *node, const char *key, const char *value)
{
	char *new_value;

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(node->value);
			node->value = new_value;
			return (1);
		}
		node = node->next;
	}
	return (0);
}

/**
 * insert_sorted - inserts node in sorted linked list
 * @ht: hash table
 * @new: new node
 */
void insert_sorted(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		ht->shead = new;
		ht->stail = new;
		return;
	}

	tmp = ht->shead;
	while (tmp != NULL && strcmp(tmp->key, new->key) < 0)
		tmp = tmp->snext;

	if (tmp == ht->shead)
	{
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else if (tmp == NULL)
	{
		new->sprev = ht->stail;
		ht->stail->snext = new;
		ht->stail = new;
	}
	else
	{
		new->snext = tmp;
		new->sprev = tmp->sprev;
		tmp->sprev->snext = new;
		tmp->sprev = new;
	}
}

/**
 * shash_table_set - adds or updates an element
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	if (update_node(ht->array[index], key, value))
		return (1);

	new = create_node(key, value);
	if (new == NULL)
		return (0);

	new->next = ht->array[index];
	ht->array[index] = new;

	insert_sorted(ht, new);

	return (1);
}

/**
 * shash_table_get - retrieves value by key
 * @ht: hash table
 * @key: key
 *
 * Return: value or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
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
 * shash_table_print - prints sorted hash table
 * @ht: hash table
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
 * shash_table_print_rev - prints sorted hash table in reverse
 * @ht: hash table
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
 * shash_table_delete - deletes sorted hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node;
	shash_node_t *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(ht->array);
	free(ht);
}
