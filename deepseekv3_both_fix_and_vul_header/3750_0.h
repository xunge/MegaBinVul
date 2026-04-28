#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define CAMEL_ERROR 0
#define CAMEL_ERROR_GENERIC 1
#define _(x) x

typedef int gboolean;
typedef int32_t gint;
typedef uint32_t guint32;
typedef char gchar;
typedef void* gpointer;
typedef void* GCancellable;
typedef void* GError;
typedef void* GIOStream;
typedef void* GObject;
typedef pthread_mutex_t GMutex;

typedef struct _CamelService CamelService;
typedef struct _CamelServiceClass {
    gboolean (*connect_sync)(CamelService*, GCancellable*, GError**);
} CamelServiceClass;

typedef struct {
    GMutex property_lock;
    GObject *engine;
} CamelPOP3StorePrivate;

typedef struct _CamelPOP3Store {
    CamelPOP3StorePrivate *priv;
} CamelPOP3Store;

typedef struct _CamelNetworkSettings CamelNetworkSettings;
typedef struct _CamelSettings CamelSettings;
typedef struct _CamelStream {
    GIOStream *base_stream;
} CamelStream;
typedef struct _CamelPOP3Engine {
    guint32 capa;
    gchar *line;
    CamelStream *stream;
} CamelPOP3Engine;
typedef struct _CamelPOP3Command {
    int state;
} CamelPOP3Command;

typedef enum {
    CAMEL_NETWORK_SECURITY_METHOD_STARTTLS_ON_STANDARD_PORT
} CamelNetworkSecurityMethod;

enum {
    CAMEL_POP3_ENGINE_DISABLE_EXTENSIONS = 1 << 0,
    CAMEL_POP3_CAP_STLS = 1 << 1
};

enum {
    CAMEL_POP3_COMMAND_OK = 1
};

extern CamelServiceClass *camel_pop3_store_parent_class;

#define CAMEL_POP3_STORE(x) ((CamelPOP3Store*)x)
#define CAMEL_POP3_ENGINE(x) ((CamelPOP3Engine*)x)
#define CAMEL_NETWORK_SETTINGS(x) ((CamelNetworkSettings*)x)
#define CAMEL_POP3_SETTINGS(x) ((void*)x)
#define CAMEL_NETWORK_SERVICE(x) ((void*)x)
#define CAMEL_POP3_COMMAND(x) ((CamelPOP3Command*)x)
#define CAMEL_SERVICE_CLASS(x) ((CamelServiceClass*)x)

static void g_object_unref(GObject *object) {}
static void g_clear_object(GObject **object_ptr) {}
static void g_free(gpointer mem) {}
static void g_mutex_lock(GMutex *mutex) { pthread_mutex_lock(mutex); }
static void g_mutex_unlock(GMutex *mutex) { pthread_mutex_unlock(mutex); }
static void g_propagate_error(GError **dest, GError *src) {}
static void g_set_error(GError **err, int domain, int code, const char *format, ...) {}
static void g_prefix_error(GError **err, const char *format, ...) {}
static GObject* g_object_ref(GObject *object) { return object; }

static CamelSettings* camel_service_ref_settings(CamelService *service) { return NULL; }
static gchar* camel_network_settings_dup_host(CamelNetworkSettings *settings) { return NULL; }
static CamelNetworkSecurityMethod camel_network_settings_get_security_method(CamelNetworkSettings *settings) { return 0; }
static gboolean camel_pop3_settings_get_disable_extensions(void *settings) { return FALSE; }
static GIOStream* camel_network_service_connect_sync(void *service, GCancellable *cancellable, GError **error) { return NULL; }
static CamelStream* camel_stream_new(GIOStream *base_stream) { return NULL; }
static GIOStream* camel_stream_ref_base_stream(CamelStream *stream) { return NULL; }
static void camel_stream_set_base_stream(CamelStream *stream, GIOStream *base_stream) {}
static GIOStream* camel_network_service_starttls(void *service, GIOStream *base_stream, GError **error) { return NULL; }
static CamelPOP3Engine* camel_pop3_engine_new(CamelStream *stream, guint32 flags, GCancellable *cancellable, GError **error) { return NULL; }
static CamelPOP3Command* camel_pop3_engine_command_new(CamelPOP3Engine *engine, gint arg1, gpointer arg2, gpointer arg3, GCancellable *cancellable, GError **error, const char *cmd) { return NULL; }
static gint camel_pop3_engine_iterate(CamelPOP3Engine *engine, gpointer arg1, GCancellable *cancellable, gpointer arg2) { return 0; }
static void camel_pop3_engine_command_free(CamelPOP3Engine *engine, CamelPOP3Command *pc) {}
static gboolean camel_pop3_engine_reget_capabilities(CamelPOP3Engine *engine, GCancellable *cancellable, GError **error) { return FALSE; }
static gchar* get_valid_utf8_error(gchar *str) { return NULL; }
static void camel_pop3_stream_truncate(CamelStream *stream) {}