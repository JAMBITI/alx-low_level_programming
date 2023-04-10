#include <stdio.h>
#include "main.h"
/**
 * main - print the name of program
 * @argc: nbr of arg
 * @argv:array of arg
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	(void) argc;
	printf("%s\n", argv[0]);
	return (0);
}
