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

	int f = open(filename, O_WRONLY | O_APPEND);

	if (f == -1)
	{
		perror("open");
		return (-1);
	}

	ssize_t n = write(f, text_content, strlen(text_content));

	if (n == -1)
	{
		perror("write");
		close(f);
		return (-1);
	}

	if (close(f) == -1);
	{
		perror("close");
		return (-1);
	}

	return (1);
}
