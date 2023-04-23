#include "main.h"

/**
 * read_textfile - function that reads a text file
 * & prints to POSIX standard output
 *
 * @fn: *filename
 *
 * @l: letters to read and print
 *
 * Return: actual number of letters it could read and print or 0 if =
 * file can not be opened or read
 * filename is NULL
 * write fails or does not write expected amount of bytes
 */

ssize_t read_textfile(const char *fn, size_t l)
{
	
	if (fn == NULL)
	{
		return (0);

	}

	int f = open(fn, O_RDONLY);

	if (f == -1)
	{
		return (0);
	}

	char *b = malloc(l);

	if (b == NULL)
	{
		close(f);
		return (0);
	}

	ssize_t tb = 0;
	ssize_t br;

	do {
		br = read(f, b, l);
		if (br == -1)
		{
			free(b);
			close(f);
			return (0);
		}

		ssize_t bw = write(STDOUT_FILENO, b, br);

		if (bw == -1 || bw != br)
		{
			free(b);
			close(f);
			return (0);
		}

		tb += bw;
	} while (br > 0);

	free(b);
	close(f);

	return (tb);
}
