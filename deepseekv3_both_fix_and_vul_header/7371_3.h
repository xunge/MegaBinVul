#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct _GString GString;
typedef unsigned int guint;
typedef char gchar;

#define HEADER_CONTENT_TYPE 1
#define HEADER_CACHE_CONTROL 2
#define HEADER_VARY 3
#define HEADER_CONTENT_ENCODING 4
#define HEADER_DNS_PREFETCH_CONTROL 5
#define HEADER_REFERRER_POLICY 6
#define HEADER_CONTENT_TYPE_OPTIONS 7
#define HEADER_CROSS_ORIGIN_RESOURCE_POLICY 8
#define HEADER_X_FRAME_OPTIONS 9

int g_ascii_strcasecmp(const char *s1, const char *s2);
void g_string_append_printf(GString *string, const char *format, ...);
void g_critical(const char *format, ...);
int cockpit_web_response_is_simple_token(const gchar *str);
int cockpit_web_response_is_header_value(const gchar *str);