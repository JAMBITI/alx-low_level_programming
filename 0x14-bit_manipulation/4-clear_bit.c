#include "main.h"

/**
 * clear_bit - function that sets a bit to 0
 * @n: number to set bit in
 * @index: index to set bit at
 * Return: 1 if it worked, or -1 on error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{

	if (index >= 64)
		return (-1);

	if (*n & 1L << index)
		*n ^= 1L << index;
	return (1);

}
