#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)
#define GOA_IS_HTTP_CLIENT(obj) (1)
#define G_IS_CANCELLABLE(obj) (1)
#define G_OBJECT(obj) ((GObject*)(obj))
#define G_CALLBACK(func) ((void (*)(void))func)
#define TRUE true
#define FALSE false
#define SOUP_SESSION_SSL_USE_SYSTEM_CA_FILE 0
#define SOUP_SESSION_SSL_STRICT 1
#define SOUP_SESSION_USE_THREAD_CONTEXT 2
#define SOUP_METHOD_GET "GET"

typedef struct _GoaHttpClient GoaHttpClient;
typedef struct _GCancellable GCancellable;
typedef struct _GObject GObject;
typedef struct _GAsyncResult GAsyncResult;
typedef struct _GSimpleAsyncResult GSimpleAsyncResult;
typedef struct _SoupSession SoupSession;
typedef struct _SoupMessage {
    void* request_headers;
} SoupMessage;

typedef void* gpointer;
typedef char gchar;
typedef bool gboolean;
typedef void (*GAsyncReadyCallback)(GObject *source_object, GAsyncResult *res, gpointer user_data);

typedef struct {
    GSimpleAsyncResult *res;
    SoupSession *session;
    SoupMessage *msg;
    GCancellable *cancellable;
    unsigned long cancellable_id;
    gboolean accept_ssl_errors;
} CheckData;

typedef struct {
    gchar *username;
    gchar *password;
} CheckAuthData;

void http_client_check_cancelled_cb(void);
void http_client_authenticate(void);
void http_client_check_auth_data_free(void);
void http_client_check_response_cb(void);
void http_client_request_started(void);

GSimpleAsyncResult* g_simple_async_result_new(GObject *obj, GAsyncReadyCallback callback, gpointer user_data, void* source);
SoupSession* soup_session_async_new_with_options(int opt1, gboolean val1, int opt2, gboolean val2, int opt3, gboolean val3, void* null);
SoupMessage* soup_message_new(const char *method, const char *uri);
void soup_message_headers_append(void *headers, const char *name, const char *value);
GCancellable* g_object_ref(GCancellable *cancellable);
unsigned long g_cancellable_connect(GCancellable *cancellable, void *callback, void *data, void *null);
void g_simple_async_result_set_check_cancellable(GSimpleAsyncResult *res, GCancellable *cancellable);
void* g_slice_new0(size_t size);
gchar* g_strdup(const gchar *str);
void g_signal_connect_data(SoupSession *session, const char *signal, void *callback, void *data, void *free_func, int flags);
void g_signal_connect(SoupSession *session, const char *signal, void *callback, void *data);
void soup_session_queue_message(SoupSession *session, SoupMessage *msg, void *callback, void *data);

#define g_slice_new0(type) ((type*)calloc(1, sizeof(type)))