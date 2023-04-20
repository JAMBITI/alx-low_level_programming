#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - a function given as a parameter
 * on each element of an array
 * @array:array to execute function
 * @size:is the size of the array
 * @action: a pointer to the function you need to use
 * Return: void
 *
 */

void array_iterator(int *array, size_t size, void (*action)(int));
{
	int *fin = array + size - 1;

		if (array && size && action)
			while (array <= fin)
				action(*array++);
}
