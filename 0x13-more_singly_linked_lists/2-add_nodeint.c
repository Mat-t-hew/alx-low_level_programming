#include"lists.h"
#include <stdio.h>

/**
 * add_nodeint -  adds new node at beginning of listint_t list
 *
 * @head: pointer to first node of head of linked list
 *
 * @n: interger for new node
 *
 * Return: address of the new element, or NULL in the event of failier
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new__x;

	new__x = malloc(sizeof(listint_t));
	if (!new__x)
	{
		return (NULL);
	}

	new__x->n = n;
	new__x->next = *head;

	*head = new__x;

	return (new__x);
}
