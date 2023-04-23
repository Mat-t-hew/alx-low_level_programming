#include "main.h"

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
	if (filename == NULL || text_content == NULL)
	{
		return (-1);
	}

	int f = open(filename, O_WRONLY | O_APPEND);

	if (f == -1)
	{
		return (-1);
	}

	size_t len = strlen(text_content);
	ssize_t bw = write(f, text_content, len);

	close(f);

	return ((bw == (ssize_t)len) ? -1 : 1);
}
