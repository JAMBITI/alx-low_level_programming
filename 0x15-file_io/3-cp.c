#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ER_NOREAD "Error: Can't read from file %s\n"
#define ER_NOWRITE "Error: Can't write to %s\n"
#define ER_NOCLOSE "Error: Can't close fd %d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
