#include "main.h"

/**
 * flip_bits - return num of bits  be flipped to
 * transform 1 num to another
 *
 * @n: first num
 * @m: second num
 *
 * Return: num of bits to convert num
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int z = n ^ m;
	unsigned int a = 0;

	while (z)
	{
		if (z & 1ul)
			count++;
		z = z >> 1;
	}
	return (count);
}
