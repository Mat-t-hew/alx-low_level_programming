#include <stdio.h>

/**
 * main - main function
 *
 * Return: always 0;
 *
 */

int main(void)
{
	long int x;

	long int sum = 0;
	long int num = 1;
	long int num2 = 2;

	printf("%ld, ", num);
	printf("%ld, ", num2);

	for (x = 0; x < 92; x++)
	{
		sum = num + num2;
		num = num2;
		num2 = sum;
		printf(", %ld", sum);

		if (x != 96)
		{
			printf(",");
			printf(" ");
		}
	}


	printf("\n");
	return (0);

}
