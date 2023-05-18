#include "main.h"

/**
 * get_endianness - returns the endiannes
 *
 * Return: 0 for big endian, 1 for small
 */

int get_endianness(void)
{
	unsigned long int a = 1;

	return (*(char *)&a);
}

