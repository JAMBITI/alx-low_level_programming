#ifndef MAIN_H
#define MAIN_H
#define READ_BUF_SIZE 1024

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int _putchar(char c);

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
#endif
