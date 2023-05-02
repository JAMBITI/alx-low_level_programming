#inclue "lists.h"

/**
 * pop_listint - A fonction deletes head node of a list
 * @head: pointer to listint t structure
 * Return: value of popped node
 */

int pop_listint(listint_t **head)
{
	listint_t *node;
	int n;

	if (*head == NULL)
		return (0);
	n = (*head)->n;
	node = (*head)->next;
	free(*head);
	*head = node;
	return (n);
}
