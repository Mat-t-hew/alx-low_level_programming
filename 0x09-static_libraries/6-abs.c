#include "main.h"

/**
 * _abs -  will computes the absolute value of an integer
 * @b: b is an integer
 *Return: integer
 */

int _abs(int b)
{
	if (b > 0)
	{
		return (b);
	}
	else if (b < 0)
	{
		return (-b);
	}
	else
	{
		return (b);
	}
}
