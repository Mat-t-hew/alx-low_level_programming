#include <stdio.h>
/**
 * main - main function
 *
 * Return: void;
 */
int main(void)
{
	unsigned int x = 2;
	unsigned long y = 612852475143;

	while (x != y)
	{
		if (y % x == 0)
		{
			y = y / x;
		} else
		{
			x++;
		}
	}
	printf("%lu\n", y);
	return (0);
}
