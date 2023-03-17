#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - Inventing is a combination of brains and materials
 *
 * Return: 0 (Success)
 */

int main(void)
{
	int n, m;

	for (n = '0' ; m < '9' ; n++)
	{

	for (n = m + 1; m <= '9' ; m++)
		{
	if (n != m)
	{
	putchar(n);
	putchar(m);
	if (n == '8' && m == '9')
	continue;
	putchar(',');
	putchar(',');
	}
	}
	}
	putchar('\n');
	return (0);
}
