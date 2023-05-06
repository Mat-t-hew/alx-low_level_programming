#include <stdio.h>
#include "main.h"

/**
 * clear_bit - function that sets value of a bit to 0 at a given index
 *
 * @idx:  index, starting from 0 of bit you want to set
 *
 * @n: unsigned long integer
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int idx)
{
	if (idx >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n ^= (-(((*n >> idx) & 1) == 1) ^ *n) & (1UL << idx);

	return (1);
}

