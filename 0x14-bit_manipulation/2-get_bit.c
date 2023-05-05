#include "main.h"

/**
 * get_bit - returns the value of bit at index in dec
 * @n: num to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int val_of_bit;

	if (index > 63)
		return (-1);



	val_of_bit = (n >> index) & 1;

	return (val_of_bit);

}
