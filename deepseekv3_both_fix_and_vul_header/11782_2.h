#include <limits.h>

struct _GObjectClass {
    void (*get_property)();
    void (*set_property)();
    void *padding[16];
};

typedef struct _GObjectClass GObjectClass;
typedef struct _PolkitUnixGroupClass PolkitUnixGroupClass;

struct _PolkitUnixGroupClass {
    GObjectClass parent_class;
};

#define G_OBJECT_CLASS(klass) ((GObjectClass*)klass)
#define G_MININT INT_MIN
#define G_MAXINT INT_MAX

#define G_PARAM_CONSTRUCT (1 << 0)
#define G_PARAM_READWRITE (1 << 1)
#define G_PARAM_STATIC_NAME (1 << 2)
#define G_PARAM_STATIC_BLURB (1 << 3)
#define G_PARAM_STATIC_NICK (1 << 4)

enum {
    PROP_GID = 1
};

void g_object_class_install_property(GObjectClass *oclass,
                                    unsigned int property_id,
                                    void *pspec);

void* g_param_spec_int(const char *name,
                       const char *nick,
                       const char *blurb,
                       int minimum,
                       int maximum,
                       int default_value,
                       unsigned int flags);

void polkit_unix_group_get_property();
void polkit_unix_group_set_property();