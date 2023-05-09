#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * read_textfile - reads text from the  file and prints it to STDOUT
 * @filename: name of file to read
 * @letters: number of letters  to read
 *
 * Return: number bytes read
 *
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd, w, t;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	t = read(fd, buffer, letters);
	w = write(STDOUT_FILENO, buffer, t);

	free(buffer);
	close(fd);
	return (w);
}
