#include <stdio.h>
#include "main.h"
/**
 * main - print the name of program
 * @argc: nbr of arg
 * @argv:array of arg
 * Return: always 0
 */
int main(int argc__attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
