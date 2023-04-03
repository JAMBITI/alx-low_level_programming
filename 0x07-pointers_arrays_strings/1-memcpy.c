#include "main.h"
/**
 * _memcpy - this function copy the memoru area
 * @dest: destination of our copies
 * @src: source of our copies
 * @n: numer of bytes
 * Return: copied memory with n byetes changed
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int a;
	int i = n;

	for (a = 0; a < i; a++)
	{ 
		dest[a] = src[a];
		n--;
	}
	return (dest);
}
