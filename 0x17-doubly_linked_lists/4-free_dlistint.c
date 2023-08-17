#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the linked list.
 * @index: The index of the node, starting from 0.
 * Return: The nth node of the dlistint_t linked list, or NULL if not found.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int currentIndex;

	if (!head)
		return (NULL);

	for (currentIndex = 0; head->next && currentIndex
	< index; currentIndex++, head = head->next)
		;

	if (currentIndex == index)
		return (head);

	return (NULL);
}
