#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: Pointer to the head of the doubly linked list
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t node_count = 0;

    for (; h; h = h->next, node_count++)
        printf("%d\n", h->n);

    return (node_count);
}
