#include <stddef.h>

typedef struct _GdmDisplayStore GdmDisplayStore;
typedef struct _GdmDisplay GdmDisplay;
typedef struct _GdmManager GdmManager;
typedef struct _GdmManagerPrivate GdmManagerPrivate;

struct _GdmManagerPrivate {
    void *object_manager;
};

struct _GdmManager {
    GdmManagerPrivate *priv;
};

enum {
    DISPLAY_REMOVED,
    N_SIGNALS
};
static unsigned int signals[N_SIGNALS];

static void on_display_status_changed(GdmDisplay *display, GdmManager *manager) {}

GdmDisplay* gdm_display_store_lookup(GdmDisplayStore *store, const char *id) { return NULL; }
void g_dbus_object_manager_server_unexport(void *manager, const char *id) {}
void g_signal_handlers_disconnect_by_func(void *instance, void *func, void *data) {}
void g_signal_emit(GdmManager *manager, unsigned int signal_id, int param, const char *id) {}
#define G_CALLBACK(f) ((void (*)(void))f)