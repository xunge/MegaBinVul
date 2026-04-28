#include <stddef.h>
#include <stdarg.h>

typedef int gboolean;
typedef unsigned long gsize;

struct GError {
    int domain;
    int code;
    char* message;
};
typedef struct GError GError;

struct GVariant;
typedef struct GVariant GVariant;

struct GDBusProxy;
typedef struct GDBusProxy GDBusProxy;

struct GDBusConnection;
typedef struct GDBusConnection GDBusConnection;

typedef struct GdmDisplay GdmDisplay;

typedef struct GdmDisplayPrivate {
    GDBusConnection *connection;
    GDBusProxy *accountsservice_proxy;
    gboolean have_existing_user_accounts;
} GdmDisplayPrivate;

static GdmDisplayPrivate* gdm_display_get_instance_private(GdmDisplay* self) { return NULL; }
static GDBusProxy* g_dbus_proxy_new_sync(GDBusConnection* c, int f, void* ca, const char* n, const char* o, const char* i, void* cb, GError** e) { return NULL; }
static GVariant* g_dbus_proxy_call_sync(GDBusProxy* p, const char* m, GVariant* pa, int f, int t, void* c, GError** e) { return NULL; }
static void g_variant_get(GVariant* v, const char* f, ...) {}
static gsize g_variant_n_children(GVariant* v) { return 0; }
static void g_variant_unref(GVariant* v) {}
static void g_clear_error(GError** e) {}
static void g_warning(const char* f, ...) {}
static void g_critical(const char* f, ...) {}