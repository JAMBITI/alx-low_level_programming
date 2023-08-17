#include "lists.h"

/**
 * sum_dlistint - Calculates the sum of all the data
 * (n) in a dlistint_t linked list.
 * @head: Pointer to the head of the linked list.
 * Return: The calculated sum or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int totalSum;

	for (totalSum = 0; head; head = head->next)
		totalSum += head->n;
	return (totalSum);
}
