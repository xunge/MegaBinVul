#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#define AUTH_ERROR -1
#define AUTH_NO_TOKENS -2
#define AUTH_NOT_FOUND -3
#define AUTH_FOUND 0

#define D(debug_file, ...) fprintf(debug_file, __VA_ARGS__)