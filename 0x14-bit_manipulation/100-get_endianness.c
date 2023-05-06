#include "main.h"
#include <stdio.h>

/**
 * get_endianness - a function that checks the endianness
 *
 * Return: 1 if little endian or 0 if big endian
 */

int get_endianness(void)
{
	unsigned int value = 0x00000001;
	char *bytes = (char *) &value;

	if (*bytes == 0x01)
	{
		return (1);
	}

	else
	{
		return (0);
	}
}

