#include "hash_tables.h"

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
