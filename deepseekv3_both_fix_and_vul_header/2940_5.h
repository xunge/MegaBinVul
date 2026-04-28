#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef void* gpointer;
typedef unsigned int guint;
typedef int gint;
typedef size_t gsize;
typedef char gchar;

typedef struct _SoupSession SoupSession;

typedef struct {
    int status_code;
    struct {
        char* data;
        size_t length;
    } *response_body;
} SoupMessage;

typedef struct {
    SoupSession* session;
    SoupMessage** msgs;
    void* res;
    gboolean accept_ssl_errors;
} AutodiscoverData;

typedef struct _xmlDoc xmlDoc;
typedef struct _xmlNode {
    char* name;
    struct _xmlNode* children;
    struct _xmlNode* next;
} xmlNode;

typedef enum {
    SOUP_STATUS_NONE,
    SOUP_STATUS_CANCELLED,
    SOUP_STATUS_OK
} SoupStatusCode;

typedef enum {
    GTLS_CERTIFICATE_UNKNOWN_CA = 1 << 0,
    GTLS_CERTIFICATE_BAD_IDENTITY = 1 << 1,
    GTLS_CERTIFICATE_NOT_ACTIVATED = 1 << 2,
    GTLS_CERTIFICATE_EXPIRED = 1 << 3,
    GTLS_CERTIFICATE_REVOKED = 1 << 4,
    GTLS_CERTIFICATE_INSECURE = 1 << 5,
    GTLS_CERTIFICATE_GENERIC_ERROR = 1 << 6
} GTlsCertificateFlags;

#define GOA_ERROR (0)
typedef enum {
    GOA_ERROR_FAILED
} GoaError;

typedef struct {
    int domain;
    int code;
    char* message;
} GError;

/* Function pointer declarations */
void (*ews_client_autodiscover_data_free)(void*);
int (*ews_client_check_node)(xmlNode*, const char*);
int (*ews_client_autodiscover_parse_protocol)(xmlNode*);
void (*g_set_error)(GError**, int, int, const char*, ...);
const char* (*_)(const char*);
gboolean (*soup_message_get_https_status)(SoupMessage*, void*, GTlsCertificateFlags*);
void (*goa_utils_set_error_ssl)(GError**, GTlsCertificateFlags);
void (*soup_buffer_free)(void*);
void* (*soup_message_body_flatten)(void*);
void (*g_debug)(const char*, ...);
xmlDoc* (*xmlReadMemory)(const char*, int, const char*, const char*, int);
xmlNode* (*xmlDocGetRootElement)(xmlDoc*);
int (*g_strcmp0)(const char*, const char*);
void (*soup_session_cancel_message)(SoupSession*, SoupMessage*, int);
void (*g_clear_error)(GError**);
void (*g_simple_async_result_take_error)(void*, GError*);
void (*g_simple_async_result_set_op_res_gboolean)(void*, gboolean);
void (*g_simple_async_result_complete_in_idle)(void*);
guint (*g_idle_add)(void (*)(void*), void*);

/* Macro for SOUP_MESSAGE cast */
#define SOUP_MESSAGE(msg) ((SoupMessage*)(msg))