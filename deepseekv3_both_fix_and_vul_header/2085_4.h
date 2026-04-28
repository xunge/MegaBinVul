#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _GypsyServer GypsyServer;
typedef struct _GypsyServerPrivate GypsyServerPrivate;
typedef struct _GypsyClient GypsyClient;
typedef struct _GList {
    void *data;
    struct _GList *next;
    struct _GList *prev;
} GList;
typedef bool gboolean;
typedef void* DBusGConnection;
typedef void* DBusGMethodInvocation;
typedef void* GObject;
typedef void* GError;

#define GET_PRIVATE(obj) ((GypsyServerPrivate*)0)
#define GYPSY_TYPE_SERVER 0
#define GYPSY_TYPE_CLIENT 0
#define GYPSY_GPS_PATH "/org/gnome/Gypsy/"
#define GYPSY_NOTE(domain, ...)
#define GYPSY_SERVER_ERROR 0
#define GYPSY_SERVER_ERROR_BAD_PATH 0
#define FALSE false
#define TRUE true

static inline int g_source_remove(unsigned int id) { return 0; }
static inline int g_str_equal(const char *a, const char *b) { return strcmp(a, b) == 0; }
static inline int g_pattern_match_simple(const char *pattern, const char *str) { return 0; }
static inline void g_warning(const char *format, ...) {}
static inline void* g_error_new(int domain, int code, const char *format, ...) { return NULL; }
static inline void dbus_g_method_return_error(void *context, void *error) {}
static inline void g_error_free(void *error) {}
static inline char* g_path_get_basename(const char *path) { return NULL; }
static inline char* g_strdup_printf(const char *format, ...) { return NULL; }
static inline char* g_strdelimit(char *str, const char *delimiters, char new_delimiter) { return NULL; }
static inline void g_free(void *ptr) { free(ptr); }
static inline void* dbus_g_connection_lookup_g_object(void *connection, const char *path) { return NULL; }
static inline void* g_object_new(int type, const char *prop, const char *value, ...) { return NULL; }
static inline void dbus_g_connection_register_g_object(void *connection, const char *path, void *object) {}
static inline void* G_OBJECT(void *obj) { return obj; }
static inline void g_object_ref(void *obj) {}
static inline char* dbus_g_method_get_sender(void *context) { return NULL; }
static inline void* g_hash_table_lookup(void *hash_table, const char *key) { return NULL; }
static inline GList* g_list_prepend(GList *list, void *data) { return NULL; }
static inline void g_hash_table_insert(void *hash_table, void *key, void *value) {}
static inline void dbus_g_method_return(void *context, const char *path) {}

struct _GypsyServerPrivate {
    DBusGConnection *connection;
    void* connections;
    char **allowed_device_globs;
    int allowed_device_glob_count;
    unsigned int terminate_id;
    int client_count;
};