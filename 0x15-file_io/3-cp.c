#include "main.h"
#include <stdio.h>

/**
 * cp - program that copies the content of a file to another file
 *
 * main - entry point for the program
 *
 * @argc: an integer variable that represent number of argument passed to prog
 *
 * @argv: is a pointer to an array of characters
 *
 * Return: 1 on success ,2 or 3 if error is can't read or write respectively
 */

int main(int argc, char *argv[])
{
	FILE *from, *to;
	int c;

	if (argc != 3)
	{
		printf("Usage: cp file_from file_to\n");
		return (1);
	}
	from = fopen(argv[1], "r");

	if (from == NULL)
	{
		printf("Error: Can't read from file %s\n", argv[1]);
		return (2);
	}
	to = fopen(argv[2], "w");

	if (to == NULL)
	{
		printf("Error: Can't write to file %s\n", argv[2]);
		return (3);
	}

	while ((c = fgetc(from)) != EOF)
	{
		fputc(c, to);
	}

	fclose(from);
	fclose(to);

	return (0);
}


