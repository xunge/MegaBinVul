#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef char gchar;
typedef unsigned char guint8;

static int g_ascii_strncasecmp(const char *s1, const char *s2, size_t n) {
    while (n--) {
        gchar c1 = tolower(*s1++);
        gchar c2 = tolower(*s2++);
        if (c1 != c2) return c1 - c2;
        if (c1 == '\0') break;
    }
    return 0;
}

static gchar *g_strndup(const gchar *str, size_t n) {
    gchar *new_str = malloc(n + 1);
    if (new_str) {
        strncpy(new_str, str, n);
        new_str[n] = '\0';
    }
    return new_str;
}