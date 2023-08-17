#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list
 * @head: Pointer to the pointer to the first node in the list.
 * @n: Data value for the new node.
 *
 * Return: Pointer to the newly added node, or NULL if memory allocation fails.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *n_node;

	n_node = malloc(sizeof(dlistint_t));
	if (!n_node)
		return (NULL);

	n_node->n = n;
	n_node->next = *head;
	n_node->prev = NULL;

	if (*head)
	(*head)->prev = n_node;
	*head = n_node;

	return (n_node);
}
