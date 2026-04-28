#include <stddef.h>

typedef struct _GdmDisplayStore GdmDisplayStore;
typedef struct _GdmDisplay GdmDisplay;
typedef struct _GdmLocalDisplayFactory GdmLocalDisplayFactory;

typedef void (*GCallback)(void);
typedef void (*GWeakNotify)(void *data, void *user_data);

#define G_OBJECT(instance) ((void*)(instance))
#define G_CALLBACK(func) ((GCallback)(func))

void on_display_status_changed(GdmDisplay *display, GdmLocalDisplayFactory *factory);
void on_display_disposed(GdmLocalDisplayFactory *factory);
GdmDisplay* gdm_display_store_lookup(GdmDisplayStore *display_store, const char *id);

void g_signal_handlers_disconnect_by_func(void *instance, GCallback func, void *data);
void g_object_weak_unref(void *object, GWeakNotify notify, void *data);