#include <stdint.h>
#include <stddef.h>

typedef struct _GdmManager GdmManager;
typedef struct _GdmManagerClass GdmManagerClass;
typedef struct _GObjectClass {
    void (*get_property)(void);
    void (*set_property)(void);
    void (*constructor)(void);
    void (*dispose)(void);
} GObjectClass;
typedef int gboolean;
typedef unsigned int guint;
typedef char gchar;
typedef void* gpointer;
typedef int GType;
typedef int GParamSpec;
typedef int GSignalFlags;
typedef int GConnectFlags;
typedef int GClosureNotify;
typedef int GSignalAccumulator;
typedef int GSignalCMarshaller;
typedef size_t gsize;
typedef int GTypeClass;

#define G_TYPE_FROM_CLASS(class) (0)
#define G_SIGNAL_RUN_LAST (0)
#define G_STRUCT_OFFSET(type, field) (0)
#define G_TYPE_NONE (0)
#define G_TYPE_STRING (0)
#define G_TYPE_OBJECT (0)
#define G_PARAM_READWRITE (0)
#define G_PARAM_CONSTRUCT (0)
#define FALSE (0)
#define g_cclosure_marshal_VOID__STRING 0
#define g_cclosure_marshal_VOID__OBJECT 0
#define NULL 0

struct _GdmManagerClass {
    GObjectClass parent_class;
    void (*display_added)(GdmManager *manager, const gchar *id);
    void (*display_removed)(GdmManager *manager, void *display);
};

struct _GdmManagerPrivate {
    int dummy;
};

typedef struct _GdmManagerPrivate GdmManagerPrivate;

enum {
    DISPLAY_ADDED,
    DISPLAY_REMOVED,
    LAST_SIGNAL
};

static guint signals[LAST_SIGNAL];

enum {
    PROP_0,
    PROP_XDMCP_ENABLED,
    N_PROPERTIES
};

static void gdm_manager_get_property(void) {}
static void gdm_manager_set_property(void) {}
static void gdm_manager_constructor(void) {}
static void gdm_manager_dispose(void) {}

static guint g_signal_new(const gchar *signal_name,
                         GType itype,
                         GSignalFlags signal_flags,
                         guint class_offset,
                         GSignalAccumulator accumulator,
                         gpointer accu_data,
                         GSignalCMarshaller c_marshaller,
                         GType return_type,
                         guint n_params,
                         ...) { return 0; }

static void g_object_class_install_property(GObjectClass *oclass,
                                           guint property_id,
                                           GParamSpec *pspec) {}

static void g_type_class_add_private(GTypeClass *g_class, gsize private_size) {}

static GParamSpec* g_param_spec_boolean(const gchar *name,
                                      const gchar *nick,
                                      const gchar *blurb,
                                      gboolean default_value,
                                      int flags) { return 0; }

#define G_OBJECT_CLASS(klass) ((GObjectClass*)klass)