#include <stddef.h>
#include <limits.h>
#include <sys/types.h>

#define UV_EINVAL (-22)

unsigned uv__utf8_decode1(const char** s, const char* se);
int uv__idna_toascii_label(const char* s, const char* se, char** d, char* de);