#include"lists.h"
#include <stdio.h>

/**
 * add_nodeint_end - adds new node at end of listint_t list
 *
 * @head: pointer to last  node of head of linked list
 *
 * @n: interger for new node
 *
 * Return: address of the new element, or NULL in the event of failier
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new__x, *present;

	new__x = malloc(sizeof(listint_t));
	if (!new__x)
	{
		return (NULL);
	}

	new__x->n = n;
	new__x->next = NULL;

	if (*head == NULL)
	{
		*head = new__x;
	}

	else
	{
		present = *head;
		while (present->next != NULL)
		{
			present = present->next;
		}

		present->next = new__x;
	}

	return (new__x);
}

