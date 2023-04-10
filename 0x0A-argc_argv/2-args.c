#include <stdio.h>
#include "main.h"
/**
 * main - prints all arguments it receives
 * @argc: nmbr of arg
 * @argv: array of arg
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
