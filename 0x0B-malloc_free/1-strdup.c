#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: char
 * Return: Always 0
 */
char *_strdup(char *str)
{
	char *x;
	int i;
	int z = 0;

	if (str == NULL)
		return (NULL)

	i = 0;
	while (str[i] != '\0')
		i++;
	x = malloc(sizeof(char) * (i + 1));

	if (x == NULL)
		return (NULL);

	for (z = 0, str[z]; z++)
	x[z] = str[z];
	return (x);
}
