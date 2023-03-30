#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t lis
 * @head: head of linked list
 * @n: interger
 * Return: address of the n ew element or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

