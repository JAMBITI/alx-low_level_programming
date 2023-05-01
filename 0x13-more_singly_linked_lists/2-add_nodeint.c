#include "lists.h"

/**
 * add_nodeint - adds a node to the top
 * @head: pointer to first node
 * @n: value for new node
 *
 * Return: pointer to new node
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (!head || !new)
		return (NULL);

	new->next = NULL;
	new->n = n;
	if (*head)
		new->next = *head;
	*head = new;
	return (new);
}
