#include <stdlib.h>
#include "main.h"
/**
 * *malloc_checked - allocates memory with malloc
 * @b: nmbr of bytes to allocated
 * Return: a pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *a;

	a = malloc(b);

	if (a == NULL)
		exit(98);

	return (a);
}


