#include <stdint.h>
#include <sys/types.h>

#define UINT_MAX 4294967295U
#define UV_EINVAL -22

ssize_t uv__idna_toascii_label(const char* s, const char* se, char** d, char* de);
unsigned uv__utf8_decode1(const char** s, const char* se);