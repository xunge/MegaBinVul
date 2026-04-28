#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAXSTRING 1024
#define DIR_SEP '/'
#define LOU_LOG_DEBUG 0

void _lou_logMessage(int level, const char *format, ...);