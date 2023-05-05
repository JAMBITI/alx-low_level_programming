#include "main.h"

/**
 * print_binary - prints a num as bin str
 * @n: the number to print
 *
 * Return: void
 */

void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int z;

	for (i = 63; i >= 0; i--)
	{
		z = n >> i;

		if (z & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');



}
