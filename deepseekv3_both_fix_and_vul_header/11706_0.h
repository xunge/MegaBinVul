#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <execinfo.h>

#define LOG_INFO 0
void log_message(int level, const char *format, ...);