#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ER_NOREAD "Error: Can't read from file %s\n"
#define ER_NOWRITE "Error: Can't write to %s\n"
#define ER_NOCLOSE "Error: Can't close fd %d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * main - master program
 *
 * @co: argument count
 * @ve: argument vector
 *
 * Return: 1 on success 0 on failure
 */


int main(int co, char **ve)
{
	int fr_fd = 0, to_fd = 0;
	ssize_t z;
	char buf[READ_BUF_SIZE];

	if (co != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	fr_fd = open(ve[1], O_RDONLY);
	if (from_fd == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, ve[1]), exit(98);
	to_fd = open(ve[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (to_fd == -1)
		dprintf(STDERR_FILENO, ER_NOWRITE, ve[2]), exit(99);

	while ((z = read(from_fd, buf, READ_BUF_SIZE)) > 0)
		if (write(to_fd, buf, z) != z)
			dprintf(STDERR_FILENO, ER_NOWRITE, ve[2]), exit(99);
	if (z == -1)
		dprintf(STDERR_FILENO, ER_NOREAD, ve[1]), exit(98);

	fr_fd = close(fr_fd);
	to_fd = close(to_fd);
	if (fr_fd)
		dprintf(STDERR_FILENO, ER_NOCLOSE, fr_fd), exit(100);
	if (to_fd)
		dprintf(STDERR_FILENO, ER_NOCLOSE, fr_fd), exit(100);

	return (EXIT_SUCCESS);
}
