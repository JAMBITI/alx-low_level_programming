#include "lists.h"

/**
 * free_listint2 - frees a list and set head to null
 * @head: address of pointer to listing structure
 *
 * Return: nothing
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	temp = *head;
	while (*head)
	{
		temp = *head;
		(*head) = (*head)->next;
		free(temp);

	}
	*head = NULL;
}
