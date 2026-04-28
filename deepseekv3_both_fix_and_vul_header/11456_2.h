#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef unsigned int gunichar;
typedef unsigned char guchar;
typedef unsigned int guint;
typedef char gchar;
typedef ptrdiff_t gssize;
typedef void* gpointer;

gunichar g_utf8_get_char_validated(const gchar *p, gssize max_len);
gchar* g_strdup_printf(const gchar *format, ...);
void g_free(gpointer mem);
void char_str(gunichar c, gchar *buf);