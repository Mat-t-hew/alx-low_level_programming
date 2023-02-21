#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - prints numbers to 98
 * @b: starting integer
 * Description: prints all natural number from n - 98
 * Return: void
 */

void print_to_98(int b)
{
	if (b < 98)
	{
		while (b < 98)
		{
			printf("%d, ", b);
			b++;
		}
	}
	else if (b > 98)
	{
		while (b > 98)
		{
			printf("%d, ", b);
			b--;
		}
	}
	printf("98\n");
}
