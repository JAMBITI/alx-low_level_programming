#include "lists.h"
#include <stdio.h>

/**
 * print_list - A function that prints a linked list
 * @h: pointer t  head of list
 * Return: number of nodes in list as size_t
 */


size_t print_list(const list_t *h)
{
		size_t b = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		b++;
	}

	return (b);
}
