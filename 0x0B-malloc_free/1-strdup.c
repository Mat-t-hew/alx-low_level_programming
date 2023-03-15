#include "main.h"
#include <stdlib.h>

/**
 *  * _strdup - function that returns a pointer to newly allocated - in memory
 *   * @str: char variable
 *    * Return: NULL
 */

char *_strdup(char *str)
{
	char *p;
	unsigned int i, j;

		if (str == NULL)
		{
		return (NULL);
		}
		j = 0;
		while (str[j] != '\0')
		{
		j++;
		}
		j++;
		p = malloc(sizeof(char) * j);
		if (p == NULL)
		return (NULL);
		i = 0;
		while (str[i] != '\0')
		{
			p[i] = str[i];
			i++;
		}
			p[i] = '\0';
		return (p);
}
