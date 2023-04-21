#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>


/**
 * print_strings - Entry Point
 * @separator: comma space
 * @n: number of elements
 * Return: void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	int i = x;
	char *s;
	va_list valist;

	if (!x)
		printf("\n");
	va_start(valist, x);
	while (i--)
		printf("%s%s", (s = va_arg(valist, char *)) ? s : "(nil)",
				i ? (separator ? separator : "") : "\n");
	va_end(valist);
}
