#include <stdlib.h>
#include <string.h>

typedef size_t gsize;
typedef char gchar;

char *g_strdup(const char *str);
void g_base64_decode_inplace(char *text, gsize *out_len);
gchar *g_base64_decode(const char *text, gsize *out_len);