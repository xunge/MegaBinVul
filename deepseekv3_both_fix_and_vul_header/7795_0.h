#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#define MOBI_ATTRNAME_MAXSIZE 255
#define MOBI_ATTRVALUE_MAXSIZE 4096
#define SIZE_MAX ((size_t)-1)

void debug_print(const char *format, ...);