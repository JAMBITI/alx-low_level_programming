#include "lists.h"

/**
 * get_nodeint_at_index - function that returns node at index
 * @head: pointer to listint_t
 * @index: index of node
 *
 * Return: pointer to node, or NULL if it's not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
	temp = temp->next;
	i++;

	}
	return (temp ? temp : NULL);
}



