#ifndef _LISTS_H
#define _LISTS_H
#include <stdlib.h>

/**
 * Struct list_s - Singly linked list
 * @Str: String
 * @len: Length of string
 * @next: Points to the next node
 *
 * Description: Singly linked list node structure project
 */

typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);

#endif
