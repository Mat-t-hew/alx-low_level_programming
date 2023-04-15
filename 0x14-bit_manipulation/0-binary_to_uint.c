#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - function that converts binary number to an unsigned int
 *
 * @b: binary string of 0 and 1 chars
 *
 * Return: converted number, or 0 if
 * there is one or more chars in string b that is not 0 or 1
 * b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	 int a = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (b[a] != '\0')
	{
		if (b[a] == '0')
		{
			result = result << 1;
		}

		else if (b[a] == '1')
		{
			result = (result << 1) | 1;
		}

		else
		{
			return (0);
		}

		a++;
	}

	return (result);
}
