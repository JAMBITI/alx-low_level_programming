#include "main.h"
/**
 * _memset -  fills the first n with a value
 * @s: adress to be filled
 * @b: desired value
 * @n: size to be changed
 * Return: changed with new vakue
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;
	for (i = 0; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
