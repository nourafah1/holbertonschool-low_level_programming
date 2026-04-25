#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at given index
 * @h: pointer to head
 * @idx: index
 * @n: value
 *
 * Return: address of new node, or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return (NULL);

	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	new->next = temp->next;
	new->prev = temp;
	temp->next->prev = new;
	temp->next = new;

	return (new);
}
