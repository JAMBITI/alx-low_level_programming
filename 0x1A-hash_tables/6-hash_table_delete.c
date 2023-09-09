#include "hash_tables.h"

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
