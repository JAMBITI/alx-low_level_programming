#include "main.h"
/**
 * _strlen_recursion - function that returns the length of a string.
 * @s: string to be mesured
 * return:length of string
 */
int _strlen_recursion(char *s)
{
	int lenstr = 0;

	if (*s != '\0')
	{
		lenstr++;
		lenstr += _strlen_recursion(s + 1);
	}

	return (lenstr);
}
