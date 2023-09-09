#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in the hash table.
 * @ht: The hash table to add/update the key/value pair.
 * @key: The key (cannot be empty).
 * @value: The value associated with the key.
 *
 * Return: 1 if the operation succeeds, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
hash_node_t *new_node, *current_node;

if (!ht || !key || !value || *key == '\0')
return (0);

/* Get the index using the hash function */
index = key_index((const unsigned char *)key, ht->size);

/* Search for an existing node with the same key */
current_node = ht->array[index];
while (current_node)
{
if (strcmp(current_node->key, key) == 0)
{
/* Update the value if the key already exists */
free(current_node->value);
current_node->value = strdup(value);
if (!current_node->value)
return (0);
return (1);
}
current_node = current_node->next;
}

/* Create a new node and add it to the beginning of the linked list */
new_node = malloc(sizeof(hash_node_t));
if (!new_node)
return (0);

new_node->key = strdup(key);
if (!new_node->key)
{
free(new_node);
return (0);
}

new_node->value = strdup(value);
if (!new_node->value)
{
free(new_node->key);
free(new_node);
return (0);
}

/* Update the head of the linked list at the calculated index */
new_node->next = ht->array[index];
ht->array[index] = new_node;

return (1);
}
