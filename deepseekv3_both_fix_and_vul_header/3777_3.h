#include <stddef.h>
#include <stdint.h>
#include <netinet/tcp.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef int gboolean;
typedef unsigned int guint;
typedef unsigned char guchar;
typedef int gint;
typedef char gchar;

typedef struct _GIOStream GIOStream;
typedef struct _GSocket GSocket;
typedef struct _GInputStream GInputStream;
typedef struct _GOutputStream GOutputStream;
typedef struct _GCancellable GCancellable;
typedef struct _GError {
    int domain;
    int code;
    char *message;
} GError;
typedef pthread_mutex_t GMutex;

typedef struct _CamelIMAPXServer CamelIMAPXServer;
typedef struct _CamelIMAPXStore CamelIMAPXStore;
typedef struct _CamelSettings CamelSettings;
typedef struct _CamelService CamelService;
typedef struct _CamelNetworkSettings CamelNetworkSettings;
typedef struct _CamelIMAPXSettings CamelIMAPXSettings;
typedef struct _CamelNetworkService CamelNetworkService;
typedef struct _GSocketConnection GSocketConnection;
typedef struct _CamelIMAPXInputStream CamelIMAPXInputStream;
typedef struct _CamelIMAPXCommand CamelIMAPXCommand;

typedef enum {
    CAMEL_NETWORK_SECURITY_METHOD_STARTTLS_ON_STANDARD_PORT
} CamelNetworkSecurityMethod;

#define IPPROTO_TCP 6
#define TCP_NODELAY 1
#define G_STRFUNC __func__
#define CAMEL_ERROR 0
#define CAMEL_ERROR_GENERIC 1
#define STARTTLS 0
#define IMAPX_CAPABILITY 0
#define CAMEL_IMAPX_JOB_CAPABILITY 0
#define CAMEL_IMAPX_JOB_STARTTLS 0
#define _(x) x

struct _CamelIMAPXServerPrivate {
    GMutex stream_lock;
    GIOStream *connection;
    GInputStream *input_stream;
    GOutputStream *output_stream;
    struct {
        unsigned int capa;
    } *cinfo;
    void *subprocess;
    char *tagprefix;
};

struct _CamelIMAPXCommand {
    struct {
        int condition;
        struct {
            struct {
                unsigned int capa;
            } *cinfo;
        } u;
    } *status;
};

struct _CamelIMAPXServer {
    struct _CamelIMAPXServerPrivate *priv;
};