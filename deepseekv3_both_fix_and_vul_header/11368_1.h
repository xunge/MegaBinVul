#include <stdlib.h>

typedef struct {
    void *store;
    void *display;
} StoredDisplay;

enum {
    DISPLAY_REMOVED,
    LAST_SIGNAL
};

static unsigned int signals[LAST_SIGNAL];

#define G_OBJECT(obj) (obj)
#define g_free free
#define g_debug printf
#define g_object_unref(obj) (free(obj))
#define g_slice_free(type, ptr) (free(ptr))