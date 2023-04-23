#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * append_text_to_file - a function that appends text at end of a file
 *
 * @filename: name of file to create
 *
 * @text_content: content to write to file
 *
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	if (filename == NULL || strlen(filename) == 0)
	{
		return (0);
	}

	FILE *file = fopen(filename, "a");

	if (file == NULL)
	{
		return (0);
	}

	fprintf(file, "%s", text_content);
	close(file);

	return (1);
}
