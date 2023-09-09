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
