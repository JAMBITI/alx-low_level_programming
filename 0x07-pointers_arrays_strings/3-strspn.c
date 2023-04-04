#include "main.h"
/**
 * _strspn - entry
 * @s: inp
 * @accept: inp
 * Returne: Always 0
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int x = 0;
	int b;

	while (*s)
	{
		for (b = 0; accept[b]; b++)
		{
			if ((*s)  == accept[b])
			{
				x++;
				break
			}
			else if (accept[b + 1] == '\0')
				return (x)
		}
		s++;
	}
	return (x);
}
