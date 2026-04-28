#include <stdlib.h>

typedef struct _GrlNetWcPrivate GrlNetWcPrivate;
typedef struct _GrlNetWc GrlNetWc;

struct _GrlNetWc {
    void* parent;
    GrlNetWcPrivate *priv;
};

struct _GrlNetWcPrivate {
    void* session;
    void* pending;
};

#define GRL_LOG_DOMAIN_INIT(domain, name)
#define grl_net_wc_get_instance_private(wc) ((GrlNetWcPrivate*)malloc(sizeof(GrlNetWcPrivate)))
#define G_OBJECT(obj) (obj)
#define TRUE 1
#define NULL 0

void* soup_session_async_new();
void g_object_set(void* obj, const char* prop, int value, void* null);
void* g_queue_new();

static void set_thread_context(GrlNetWc *wc);
static void init_mock_requester(GrlNetWc *wc);
static void init_requester(GrlNetWc *wc);