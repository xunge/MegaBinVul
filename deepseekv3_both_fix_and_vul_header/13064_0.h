#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAXSTRING 1024
#define DIR_SEP '/'

enum { LOU_LOG_DEBUG };

extern void _lou_logMessage(int level, const char *format, ...);