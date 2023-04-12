#include"lists.h"
#include <stdio.h>

/**
 * free_listint - Frees linked list for integers
 *
 * @head: pointer to last  node of head of linked list
 *
 * Return: void of linked list
 */

void free_listint(listint_t *head)
{
	listint_t *present;

	for (present = head; present != NULL; present = head)
	{
		head = head->next;
		free(present);
	}
}
