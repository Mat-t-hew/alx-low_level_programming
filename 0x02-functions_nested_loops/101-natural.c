#include <stdio.h>

/**
 * main - main function
 *
 * Return: always 0
 *
 */

int main(void)
{
	int x;
	int y = 0;

	for (x = 0; x < 1024; x++)
	{
		if (x % 3 == 0 || x % 5 == 0)
		{
			y += x;
		}
	}
	printf("%d\n", y);
	return (0);
}
