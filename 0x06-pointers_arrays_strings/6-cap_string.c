#include "main.h"

/**
 * cap string - function that capitalizes all words of a string.
 * @str: the string to be capitilized.
 * Return: A pointer to the changed string.
 */

char *cap_string(char *str)
{
	int i = 0;

	while (str[i])
	{
		while (!(str[i] >= 'a' && str[i] <= 'z'))
			i++;
		if ((str[i - 1] == ((' ') || ('\t') || ('\n') || (',') || (';') || ('.') || ('!') || ('?') || ('"') || ('(') || (')') || ('{') || ('}') || (0))
			str[i] -= 32;
			i++;
			}
			return (str);
}
