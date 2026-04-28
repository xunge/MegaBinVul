#include <stdlib.h>
#include <string.h>

typedef int gboolean;
typedef const void* gconstpointer;
typedef void* gpointer;

struct _GSList {
    gpointer data;
    struct _GSList* next;
};
typedef struct _GSList GSList;

struct _SoupURI {
    char* host;
};
typedef struct _SoupURI SoupURI;

struct _SoupCookie {
    char* expires;
    gboolean http_only;
};
typedef struct _SoupCookie SoupCookie;

struct _SoupCookieJarPrivate {
    void* domains;
};
typedef struct _SoupCookieJarPrivate SoupCookieJarPrivate;

typedef struct _SoupCookieJar SoupCookieJar;

static int compare_cookies(gconstpointer a, gconstpointer b, gpointer user_data) {
    return 0;
}

static SoupCookieJarPrivate* soup_cookie_jar_get_instance_private(SoupCookieJar* jar) { return NULL; }
static char* g_strdup_printf(const char* format, ...) { return NULL; }
static void* g_hash_table_lookup(void* hash_table, const void* key) { return NULL; }
static gboolean soup_date_is_past(const char* date) { return 0; }
static GSList* g_slist_append(GSList* list, gpointer data) { return NULL; }
static GSList* g_slist_delete_link(GSList* list, GSList* link) { return NULL; }
static void g_hash_table_insert(void* hash_table, gpointer key, gpointer value) {}
static char* g_strdup(const char* str) { return NULL; }
static gboolean soup_cookie_applies_to_uri(SoupCookie* cookie, SoupURI* uri) { return 0; }
static SoupCookie* soup_cookie_copy(SoupCookie* cookie) { return NULL; }
static void g_free(void* ptr) {}
static void soup_cookie_jar_changed(SoupCookieJar* jar, SoupCookie* old_cookie, SoupCookie* new_cookie) {}
static void soup_cookie_free(SoupCookie* cookie) {}
static void g_slist_free(GSList* list) {}
static GSList* g_slist_sort_with_data(GSList* list, int (*compare_func)(gconstpointer, gconstpointer, gpointer), gpointer user_data) { return NULL; }