#include"lists.h"
#include <stdio.h>

/**
 * sum_listint - a function that returns sum of all data (n) of listint_t list
 *
 * @head: pointer to head node of linked list
 *
 * Return: sum of all data (n) or 0 if list is empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head != NULL)
	{
		listint_t *present = head;

		do {
			sum += present->n;
			present = present->next;
		} while (present != NULL);
	}

	return (sum);
}
