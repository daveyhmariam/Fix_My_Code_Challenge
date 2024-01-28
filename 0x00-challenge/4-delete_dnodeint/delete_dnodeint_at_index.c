#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	p = 0;
	tmp = *head;
	while (p < index && tmp)
	{
		tmp = tmp->next;
		p++;
	}
	if (tmp == NULL)
	{
		return (-1);
	}
	if (p == 0)
	{
		(*head) = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}
	else
	{
		if (tmp->next)
		{
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			free(tmp);
			return (1);		
		}
		else
		{
			tmp->prev->next = NULL;
			free(tmp);
			return(-1);
		}
	}
}
