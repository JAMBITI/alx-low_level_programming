#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key in the hash table.
 * @ht: The hash table.
 * @key: The key to search for.
 *
 * Return: The value associated with the key or NULL if not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int index;
hash_node_t *current_node;

if (!ht || !key || *key == '\0')
return (NULL);

/* Get the index using the hash function */
index = key_index((const unsigned char *)key, ht->size);

/* Search for the node with the given key */
current_node = ht->array[index];
while (current_node)
{
if (strcmp(current_node->key, key) == 0)
return (current_node->value);
current_node = current_node->next;
}

/* Key not found in the hash table */
return (NULL);
}
