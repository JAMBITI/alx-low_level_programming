#include "lists.h"

/**
 * listint_len - prints linked lists
 * @h: pointer first node
 *
 * Return: size of lists
 */


size_t print_listint(const listint_t *h);
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
