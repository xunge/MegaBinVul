typedef int gboolean;
typedef void* GIOChannel;
typedef unsigned int GIOCondition;
typedef void* GObject;
typedef void* IceListenObj;
typedef struct _IceConn *IceConn;
typedef int IceAcceptStatus;

typedef struct _GsmIceConnectionData GsmIceConnectionData;
typedef struct _GsmClient GsmClient;
typedef struct _GsmXsmpServer GsmXsmpServer;
typedef struct _GsmXsmpServerPrivate GsmXsmpServerPrivate;

struct _IceConn {
    void* context;
};

struct _GsmIceConnectionData {
    IceListenObj listener;
    GsmXsmpServer *server;
};

struct _GsmXsmpServer {
    GsmXsmpServerPrivate *priv;
};

struct _GsmXsmpServerPrivate {
    void* client_store;
};

#define TRUE 1
#define FALSE 0
#define IceAcceptSuccess 0
#define g_debug(...) 
#define IceAcceptConnection(listener, status) ((IceConn)0)
#define gsm_xsmp_client_new(conn) ((GsmClient*)0)
#define gsm_store_add(store, id, obj) 
#define gsm_client_peek_id(client) (0)
#define G_OBJECT(obj) ((GObject*)0)
#define g_object_unref(obj)