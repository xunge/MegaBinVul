#include <stddef.h>

enum {
    DISPLAY_ADDED,
    DISPLAY_REMOVED,
    N_SIGNALS
};

static unsigned int signals[N_SIGNALS];

typedef struct _GdmDisplayStorePrivate GdmDisplayStorePrivate;
typedef struct _GdmDisplayStoreClass GdmDisplayStoreClass;
typedef struct _GObject GObject;

struct _GObjectClass {
    void (*finalize)(GObject *object);
};

struct _GdmDisplayStoreClass {
    struct _GObjectClass parent_class;
    void (*display_added)(void *store, const char *id);
    void (*display_removed)(void *store, void *display);
};

struct _GdmDisplayStorePrivate {
    int dummy;
};

void gdm_display_store_finalize(GObject *object);
unsigned int g_signal_new(const char *name, int itype, int signal_flags,
                         int class_offset, void *accumulator, void *accu_data,
                         void *marshal, int return_type, int n_params, ...);
void g_type_class_add_private(void *klass, size_t private_size);

#define G_OBJECT_CLASS(klass) ((struct _GObjectClass*)klass)
#define G_TYPE_FROM_CLASS(klass) (0)
#define G_SIGNAL_RUN_LAST (0)
#define G_STRUCT_OFFSET(type, field) (offsetof(type, field))
#define G_TYPE_NONE (0)
#define G_TYPE_STRING (0)
#define G_TYPE_OBJECT (0)
#define g_cclosure_marshal_VOID__STRING NULL
#define g_cclosure_marshal_VOID__OBJECT NULL

typedef struct _GObjectClass GObjectClass;