#include <stdio.h>
#include "main.h"

/**
 * print_array - prints elements of an array
 * @a: array input
 * @n: n elements
 */

void print_array(int *a, int n)
{
	int i = 0;

	for (; i < n; i++)
	{
		printf("%d", *(a + i));
		if (i != (n - 1))
			printf(", ");
	}
	printf("\n");
}
