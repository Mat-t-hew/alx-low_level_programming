#include<stdio.h>
#include "lists.h"

/**
 * main - function that prints all the elements of a listint_t list
 *@h: head of linked list of type listint_t to print
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)

{
	size_t x;

	x = 0;

	do {
		x++;
                printf("%d\n", h->n);
		h = h->next;
	} while (h != NULL);
	return (x);
}

