#include <stdio.h>
#include "main.h"

/**
 * get_bit - function which returns value of bit at given index
 *
 * @n: unsigned long integer
 *
 * @idx: index, starting from 0 of bit you want to get
 *
 * Return: value of bit at index index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int idx)
{
	if (idx >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	unsigned long int a = 1;

	a <<= idx;

	return ((n & a) >> idx);
}
