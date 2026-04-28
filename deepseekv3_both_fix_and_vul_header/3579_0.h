#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define IFNAMSIZ 16
#define LOG_ERR 3

void flog(int level, const char *format, ...);