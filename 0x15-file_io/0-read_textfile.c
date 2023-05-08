#include "main.h"

/**
 * read_textfile - function that reads a text file
 * & prints to POSIX standard output
 *
 * @filename: *filename
 *
 * @letters: letters to read and print
 *
 * Return: actual number of letters it could read and print or 0 if =
 * file can not be opened or read
 * filename is NULL
 * write fails or does not write expected amount of bytes
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w, total_bytes = 0;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		return (0);
	}

	o = open(filename, O_RDONLY);
	if (o == -1)
	{
		free(buffer);
		return (0);
	}

	while ((r = read(o, buffer, letters)) > 0)
	{
		w = write(STDOUT_FILENO, buffer, r);
		if (w == -1)
		{
			free(buffer);
			close(o);
			return (0);
		}
		total_bytes += r;
	}
	free(buffer);
	close(o);

	if (r == -1)
	{
		return (0);
	}
	return (total_bytes);
}
