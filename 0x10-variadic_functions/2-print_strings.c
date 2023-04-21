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
	int i = n;
	char *s;
	va_list valist;

	if (!n)
		printf("\n");
	va_start(valist, n);
	while (i--)
		printf("%s%s", (s = va_arg(valist, char *)) ? s : "(nil)",
				i ? (separator ? separator : "") : "\n");
	va_end(valist);
}
