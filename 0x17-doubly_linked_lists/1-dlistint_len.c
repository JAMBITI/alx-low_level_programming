#include "lists.h"
/**
 * dlistint_len - returns the length of a doubly linked list
 * @h: Pointer to first node in the list.
 *
 * Return: Number of nodes in the list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t a;

	for (a = 0; h; h = h->next, a++)
		;
	return (a);
}
