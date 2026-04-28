#include <stddef.h>
#include <stdio.h>

typedef void* GObject;
typedef void* GType;
typedef unsigned int guint;
typedef void* GObjectConstructParam;
typedef void* NMConnection;
typedef void* DBusGConnection;

typedef struct {
    int domain;
    int code;
    char* message;
} GError;

typedef struct {
    void* client;
    char* dir;
} NMAGConfConnectionPrivate;

#define NMA_GCONF_CONNECTION_GET_PRIVATE(obj) ((NMAGConfConnectionPrivate*)0)
#define G_OBJECT_CLASS(x) ((struct { GObject* (*constructor)(GType, guint, GObjectConstructParam*); }*)x)
#define NM_EXPORTED_CONNECTION(x) (x)
#define DBUS_BUS_SYSTEM 0
#define NM_CONNECTION_SCOPE_USER 0

extern void* nma_gconf_connection_parent_class;

void nm_warning(const char* fmt, ...);
void g_warning(const char* fmt, ...);
void g_error_free(GError* error);
void g_object_unref(GObject* obj);
const char* g_type_name(GType type);
NMConnection* nm_exported_connection_get_connection(GObject* obj);
void utils_fill_connection_certs(NMConnection* conn);
int nm_connection_verify(NMConnection* conn, GError** error);
void utils_clear_filled_connection_certs(NMConnection* conn);
void fill_vpn_user_name(NMConnection* conn);
DBusGConnection* dbus_g_bus_get(int type, GError** error);
void nm_exported_connection_register_object(GObject* obj, int scope, DBusGConnection* bus);
void dbus_g_connection_unref(DBusGConnection* bus);
int nm_connection_lookup_setting_type_by_quark(int quark);