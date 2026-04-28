#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int Status;
typedef struct _SmsConn *SmsConn;
typedef struct _IceConn {
    void *context;
} *IceConn;
typedef struct _GsmXsmpServer GsmXsmpServer;
typedef struct _GsmClient GsmClient;
typedef struct _GsmXSMPClient GsmXSMPClient;
typedef struct _GsmIceConnectionWatch GsmIceConnectionWatch;
typedef struct _SmsCallbacks SmsCallbacks;
typedef struct _GObject GObject;

#define TRUE true
#define FALSE false
#define _(x) x
#define g_debug printf
#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)
#define G_OBJECT(x) ((GObject*)(x))
#define GSM_XSMP_CLIENT(x) ((GsmXSMPClient*)(x))

struct _GsmXsmpServer {
    struct {
        void *client_store;
        void *xsmp_sockets;
    } *priv;
};

static void free_ice_connection_watch(GsmIceConnectionWatch *data);
static GsmClient *gsm_xsmp_client_new(IceConn ice_conn);
static void gsm_store_add(void *store, const char *id, void *obj);
static const char *gsm_client_peek_id(GsmClient *client);
static void gsm_xsmp_client_connect(GsmXSMPClient *client, SmsConn sms_conn, unsigned long *mask_ret, SmsCallbacks *callbacks_ret);
static void g_object_unref(GObject *object);
static IceConn SmsGetIceConnection(SmsConn sms_conn);