#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data of a dlistint_t list
 * @head: pointer to head
 *
 * Return: sum of all nodes
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
