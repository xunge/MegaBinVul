#include <stdio.h>
#include <string.h>

#define g_snprintf snprintf

#define JANUS_LOG(level, format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#define LOG_ERR 1