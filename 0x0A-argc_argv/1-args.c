#include <stdio.h>
#include "main.h"
/**
 * main - prints the number of arguments passed
 * @argc: nmbr of arg
 * @argv: array of arg
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
