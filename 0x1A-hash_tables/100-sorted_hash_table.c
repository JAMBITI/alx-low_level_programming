#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size: size of the array
 * Return: pointer to the hash table or NULL (fail)
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *nv_table;

	nv_table = malloc(sizeof(hash_table_t));
	if (!nv_table)
		return (NULL);
	nv_table->size = size;
	nv_table->array = malloc(sizeof(hash_node_t *) * size);
	if (!nv_table->array)
		return (NULL);
	return (nv_table);
}
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
/**
 * hash_table_print - Prints the contents of a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
int i, printed = 0;
hash_node_t *node;

if (!ht)
return;

printf("{");
for (i = 0; i < (int)ht->size; i++)
{
node = ht->array[i];
while (node)
{
if (printed)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
printed = 1;
node = node->next;
}
}
printf("}\n");
}
/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
hash_node_t *node, *next_node;
unsigned long int i;

if (!ht)
return;

for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node)
{
next_node = node->next;
free(node->key);
free(node->value);
free(node);
node = next_node;
}
}

free(ht->array);
free(ht);
}
