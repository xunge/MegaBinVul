#include <stdint.h>

typedef struct _GObject {
    void *dummy;
} GObject;

typedef struct _GValue {
    int dummy;
} GValue;

typedef struct _GParamSpec {
    int dummy;
} GParamSpec;

typedef int32_t gint;
typedef uint32_t guint;

typedef struct _PolkitUnixGroup {
    GObject parent_instance;
    gint gid;
} PolkitUnixGroup;

#define POLKIT_UNIX_GROUP(object) ((PolkitUnixGroup*)(object))

enum {
    PROP_GID = 1
};

#define g_value_get_int(value) (*(int*)(value))
#define g_return_if_fail(expr) if (!(expr)) return
#define G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, id, pspec)