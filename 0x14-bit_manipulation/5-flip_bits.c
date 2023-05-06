#include <stdio.h>
#include "main.h"

/**
 * flip_bits - function that return number of bits you need
 * to flip to get from one number to another
 *
 * @n: unsigned long integer
 *
 * @m: unsigned long integer
 *
 * Return: b
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int b = 0;
	unsigned long int i = n ^ m;

	while (i != 0)
	{
		b += i & 1;
		i >>= 1;
	}

	return (b);
}
