#include "main.h"

/**
 * swap_int - main function
 * @a: first integer
 * @b: second integer
 *
 * Return: void
*/

void swap_int(int *a, int *b)
{
	int x = *a;
	int y = *b;

	*a = y;
	*b = x;
}
