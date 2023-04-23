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
	if (filename == NULL)
	{
		return (-1);
	}

	int f = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0664);

	if (f == -1)
	{
		return (-1);
	}

	ssize_t bw = 0;

	if (text_content != NULL)
	{
		size_t l = strlen(text_content);

		bw = write(f, text_content, l);
	}

	close(f);

	return ((bw == -1) ? -1 : 1);
}
