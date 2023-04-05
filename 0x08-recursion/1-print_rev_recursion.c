#include "main.h"
/**
 * _print_rev_recursion - the fuction print the reverse of string
 * @s: inp
 *
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
{
	print_rev_recursion(s + 1);
	_putchar(*s);
}
}
