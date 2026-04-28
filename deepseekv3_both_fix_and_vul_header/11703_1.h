#include <stdio.h>
#include <stdlib.h>

#define MALLOC malloc
#define LOG_INFO 0

typedef char gchar;

void log_message(int level, const char* format, ...);