#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - func prints a name
 * @name: input name
 * @f: function of name
 *
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (f && name)

		f(name);
}
