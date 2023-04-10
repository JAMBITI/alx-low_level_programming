#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * main - [rint multiplication of 2 integers
 * @argc: count arg
 * @argv: vect arg
 * Return: 0 if true and 1 if false
 */
int main(int argc, char *argv[])
{
	int x, y;

	if (argc == 1)
	{
		x = _atoi(argv[1]);
		y = _atoi(argv[2]);
		printf("%d\n", x * y);
		return (0);
	}
	printf("Error\n");
	return (1);
}
