#include "main.h"

/**
 * create_file - a function that creates a file
 *
 * @filename: name of file to create
 *
 * @text_content: content to write to file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int f, r, l = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		do {
			l++;
		} while (*(text_content + l) != '\0');
	}

	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (f == -1)
	{
		return (-1);
	}

	r = write(f, text_content, l);

	if (r == -1)
	{
		close(f);
		return (-1);
	}

	close(f);
	return (1);
}

