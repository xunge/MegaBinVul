#include <stddef.h>
#include <stdint.h>

typedef int gint;
typedef unsigned int guint;
typedef int64_t gssize;
typedef char gchar;
typedef int gboolean;
#define TRUE 1
#define FALSE 0
#define G_GSSIZE_FORMAT "ld"

typedef enum {
    HEADER_CONTENT_TYPE,
    HEADER_CONTENT_ENCODING,
    HEADER_CACHE_CONTROL,
    HEADER_VARY,
    HEADER_DNS_PREFETCH_CONTROL,
    HEADER_REFERRER_POLICY,
    HEADER_CONTENT_TYPE_OPTIONS,
    HEADER_CROSS_ORIGIN_RESOURCE_POLICY,
    HEADER_X_FRAME_OPTIONS
} HeaderFlags;

typedef enum {
    COCKPIT_WEB_RESPONSE_CACHE_FOREVER,
    COCKPIT_WEB_RESPONSE_NO_CACHE,
    COCKPIT_WEB_RESPONSE_CACHE_PRIVATE
} CockpitWebResponseCacheType;

typedef struct {
    gchar *full_path;
    gboolean chunked;
    gboolean keep_alive;
    CockpitWebResponseCacheType cache_type;
    void *filters;
    gssize out_queueable;
} CockpitWebResponse;

typedef struct {
    char *str;
    size_t len;
    size_t allocated_len;
} GString;

typedef struct {
    void *data;
    size_t size;
} GBytes;

GBytes *g_string_free_to_bytes(GString *string);
void g_string_append(GString *string, const char *val);
void g_string_append_printf(GString *string, const char *format, ...);
const gchar *cockpit_web_response_content_type(const gchar *full_path);