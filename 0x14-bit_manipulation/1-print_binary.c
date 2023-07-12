#include "main.h"

/**
 * print_binary - prints a number as binary string
 * @n: the number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1L << (sizeof(n) * 8 - 1);
	int printed = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask != 0)
	{
		if (n & mask)
		{
			_putchar('1');
			printed++;
		}
		else if (printed)
		{
			_putchar('0');
		}
		mask >>= 1;
	}
}
