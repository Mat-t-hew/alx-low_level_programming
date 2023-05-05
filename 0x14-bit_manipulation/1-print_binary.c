#include <stdio.h>
#include "main.h"

/**
 * print_binary - function that prints binary representation of number
 *
 * @n: unsigned long integer
 *
 * Return: nothing
 */

void print_binary(unsigned long int n)
{
	unsigned long int b = 1UL << ((sizeof(unsigned long int) * 8) - 1);

	while (b > 0 && (n & b) == 0)
	{
		b >>= 1;
	}

	while (b > 0)
	{
		putchar((n & b) ? '1' : '0')
			b >>= 1;
	}
}
