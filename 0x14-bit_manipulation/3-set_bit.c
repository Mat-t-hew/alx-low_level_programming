#include <stdio.h>
#include "main.h"

/**
 * set_bit - function that sets value of a bit to 1 at a given index
 *
 * @n: unsigned long integer
 *
 * @idx: index, starting from 0 of bit you want to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int idx)
{
	if (idx >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n |= 1UL << idx;

	return (1);
}
