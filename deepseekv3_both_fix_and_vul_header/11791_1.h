#include <stdint.h>

typedef struct _GObject GObject;
typedef struct _GValue GValue;
typedef struct _GParamSpec GParamSpec;

typedef int32_t gint;
typedef uint32_t guint;

#define g_return_if_fail(expr) if (!(expr)) return
#define G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, id, spec)

typedef struct _PolkitUnixUser PolkitUnixUser;
struct _PolkitUnixUser {
    gint uid;
};

#define POLKIT_UNIX_USER(object) ((PolkitUnixUser*)(object))

static inline gint g_value_get_int(const GValue *value) {
    return *(gint*)value;
}

#define PROP_UID 1