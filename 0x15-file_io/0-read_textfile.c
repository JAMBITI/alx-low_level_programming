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
	char buf[READ_BUF_SIZE * 8];
	int fd;
	ssize_t bytes;


	if (!filename || !letters)

	return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	bytes = read(fd, &buf[0], letters);
	bytes = write(STDOUT_FILENO, &buf[0], bytes);
	close(fd);

	return (bytes);

}
