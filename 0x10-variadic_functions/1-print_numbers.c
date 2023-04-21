#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_numbers - print number
 * @n : number param
 * @separator : sep
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int ind;

	va_start(valist, n);

	for (ind = 0; ind < n; ind++)
	{
		printf("%d", va_arg(valist, int));

		if (ind != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(valist);
}
