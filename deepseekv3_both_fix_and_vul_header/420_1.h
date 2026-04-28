#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DISSECTOR_ASSERT_NOT_REACHED() abort()
#define DEBUG
#define ws_debug_printf printf

typedef int gboolean;
typedef int8_t gint8;
typedef uint8_t guint8;
typedef int32_t gint32;
typedef uint64_t guint64;
typedef int gint;

#define TRUE 1
#define FALSE 0

static char* g_strndup(const char* s, size_t n) {
    char* buf = malloc(n + 1);
    if (buf) {
        memcpy(buf, s, n);
        buf[n] = '\0';
    }
    return buf;
}

static void g_free(void* p) {
    free(p);
}

static double g_ascii_strtod(const char* nptr, char** endptr) {
    return strtod(nptr, endptr);
}