#include <stdarg.h>
#include <stdio.h>
#include <string.h>

struct GlobalConfig {
    FILE *errors;
    int mute;
};

#define ISSPACE(x) (((x) == ' ') || ((x) == '\t'))

void *curlx_mvaprintf(const char *format, va_list ap);
void curl_free(void *ptr);