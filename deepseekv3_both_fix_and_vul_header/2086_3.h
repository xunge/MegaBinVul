#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct {
    char *message;
} GError;

typedef struct {
    void *dummy;
} GKeyFile;

typedef struct {
    void *dummy;
} DBusGConnection;

typedef struct {
    void *dummy;
} GHashTable;

typedef unsigned int guint;
typedef size_t gsize;

#define GET_PRIVATE(obj) ((GypsyServerPrivate*)((char*)obj + sizeof(GypsyServer)))

typedef struct {
    DBusGConnection *connection;
    GHashTable *connections;
    guint client_count;
    guint terminate_id;
    char **allowed_device_globs;
    gsize allowed_device_glob_count;
} GypsyServerPrivate;

typedef struct {
    void *parent;
} GypsyServer;

#define DBUS_BUS_SYSTEM 0
#define G_KEY_FILE_NONE 0
#define GYPSY_CONF_GROUP "Gypsy"
#define GYPSY_CONF_GLOB_KEY "AllowedDeviceGlobs"
#define CONFIG_FILE_PATH "/etc/gypsy.conf"

DBusGConnection* dbus_g_bus_get(int, GError**);
void dbus_g_connection_ref(DBusGConnection*);
GHashTable* g_hash_table_new_full(unsigned(*)(const char*), int(*)(const char*,const char*), void(*)(void*), void(*)(void*));
GKeyFile* g_key_file_new();
int g_key_file_load_from_file(GKeyFile*, const char*, int, GError**);
char** g_key_file_get_string_list(GKeyFile*, const char*, const char*, gsize*, GError**);
void g_warning(const char*, ...);
void g_error_free(GError*);
void g_key_file_free(GKeyFile*);
unsigned g_str_hash(const char*);
int g_str_equal(const char*, const char*);
void g_free(void*);