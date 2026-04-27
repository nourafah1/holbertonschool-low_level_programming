#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

/**
 * struct hash_node_s - Node of a hash table
 * @key: key
 * @value: value
 * @next: pointer to next node
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table
 * @size: size of array
 * @array: array of linked lists
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* prototype */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
int update_value(hash_node_t *node, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
#endif
