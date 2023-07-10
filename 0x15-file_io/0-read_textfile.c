#include "main.h"

/**
 * read_textfile - read the text file and prints
 * it to the POSIX standard output
 * @filename : char text file to read
 * @letters : number of letters to be read
 * Return: number of bytes to read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int x;
	ssize_t r, w;
	char *buf;


	if (!filename)
		return (0);

	x = open(filename, O_RDONLY);

	if (x == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	r = read(x, buf, letters);
	w = write(STDOUT_FILENO, buf, r);

	close(x);

	free(buf);

	return (w);
}
