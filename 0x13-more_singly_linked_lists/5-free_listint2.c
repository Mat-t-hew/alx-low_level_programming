#include"lists.h"
#include <stdio.h>

/**
 * free_listint2 - function that frees listint_t linked list & set head to NULL
 *
 * @head: pointer to last  node of head of linked list
 *
 * Return: void of linked list
 */

void free_listint2(listint_t **head)
{
	listint_t *present = NULL;
	listint_t *next__x = NULL;

	if (head == NULL)
	{
		return;
	}


	for (present = *head; present != NULL; present = next__x)
	{
		next__x = present->next;
		free(present);
	}

	*head = NULL;
}
