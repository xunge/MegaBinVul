#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef long glong;
typedef unsigned long gulong;
typedef size_t gsize;
typedef char gchar;

#define g_assert(expr) ((void)0)
#define g_new(type, size) ((type*)malloc((size) * sizeof(type)))
#define g_free(ptr) free(ptr)
#define GPOINTER_TO_UINT(p) ((gulong)(uintptr_t)(p))

size_t g_utf8_strlen(const char *p, ssize_t max);
char *g_utf8_offset_to_pointer(const char *str, glong offset);