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
	int fd, bytes_written, length = 0;

	if (file_name == NULL)
	{
		return (-1);
	}

	if (content != NULL)
	{
		for (length = 0; content[length];)
		{
			length++;
		}
	}

	fd = open(file_name, O_WRONLY | O_APPEND);
	bytes_written = write(fd, content, length);

	if (fd == -1 || bytes_written == -1)
	{
		return -1;
	}

	close(fd);

	return (1);
}
