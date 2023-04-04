#inlude "main.h"
/**
 * _strchr: the function returns a pointer to the first occ..
 * @s: input
 * @c: input
 * Return: Always 0
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
