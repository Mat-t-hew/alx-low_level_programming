#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list
 * @head: Pointer to pointer to the head of the list
 *
 * Return: Pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head, *head = next;
	}

	return (prev);
}
