#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef char gchar;
typedef unsigned char guchar;
typedef unsigned long gulong;
typedef void* gpointer;

#define G_CHECKSUM_MD5 0

typedef struct _GString {
    char *str;
    gulong len;
    gulong allocated_len;
} GString;

typedef struct _GRecMutex {
    void *p;
    int i[2];
} GRecMutex;

typedef struct {
    GRecMutex mutex;
    gchar *server_id;
    gboolean forced_closing;
    void *worker_session;
    void *front_session;
    gchar *front_url;
    gchar *worker_url;
    gchar *server_base_url;
    gchar *key;
    gchar *server_secret;
} WebConnectionData;

typedef enum {
    MESSAGE_HELLO,
    MESSAGE_CONNECT
} MessageType;

typedef void* xmlDocPtr;
typedef void (*GDestroyNotify)(gpointer data);

typedef struct _GdaServerProvider GdaServerProvider;
typedef struct _GdaConnection GdaConnection;
typedef struct _GdaQuarkList GdaQuarkList;
typedef struct _GdaServerProviderConnectionData GdaServerProviderConnectionData;

#define GDA_IS_WEB_PROVIDER(obj) (1)
#define GDA_IS_CONNECTION(obj) (1)
#define g_return_val_if_fail(expr, val) do { if (!(expr)) return (val); } while (0)

#define _(x) x

GString* g_string_new(const char *init);
void g_string_append(GString *string, const char *val);
void g_string_append_printf(GString *string, const char *format, ...);
char* g_string_free(GString *string, int free_segment);

void* g_new0(size_t block_size, size_t n_blocks);
void g_free(void *mem);
char* g_strdup(const char *str);
char* g_strdup_printf(const char *format, ...);
char* g_compute_checksum_for_data(int checksum_type, const guchar *data, size_t length);

void g_rec_mutex_init(GRecMutex *mutex);
void g_print(const char *format, ...);

void* soup_session_new();
void* soup_session_new_with_options(const char *first_option, ...);

void xmlFreeDoc(xmlDocPtr doc);

void gda_connection_add_event_string(GdaConnection *cnc, const char *format, ...);
const gchar* gda_quark_list_find(GdaQuarkList *list, const gchar *key);
void gda_connection_internal_set_provider_data(GdaConnection *cnc, GdaServerProviderConnectionData *data, GDestroyNotify destroy_func);
gboolean do_server_setup(GdaConnection *cnc, WebConnectionData *cdata);
void _gda_web_free_cnc_data(WebConnectionData *cdata);
void _gda_web_do_server_cleanup(GdaConnection *cnc, WebConnectionData *cdata);
xmlDocPtr _gda_web_send_message_to_frontend(GdaConnection *cnc, WebConnectionData *cdata, MessageType type, const gchar *message, const gchar *secret, gchar *status);
void _gda_web_set_connection_error_from_xmldoc(GdaConnection *cnc, xmlDocPtr doc, const gchar *context);
gchar* _gda_web_compute_token(WebConnectionData *cdata);

#define sizeof_WebConnectionData (sizeof(WebConnectionData))
#define g_new0(type, n) ((type*)calloc((n), sizeof(type)))