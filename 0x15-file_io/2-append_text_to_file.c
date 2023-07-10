#include "main.h"

/**
 * append_text_to_file - append text
 * @filename : char pointer to file name
 * @text_content :  The string to add to the end of the file
 * Return: n
 */


int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, text_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
	while (text_content[text_length])
		text_length++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
	return (-1);

	bytes_written = write(file_descriptor, text_content, text_length);

	if (bytes_written == -1)
	{
	close(file_descriptor);
	return (-1);
	}

	close(file_descriptor);
	return (1);
}
