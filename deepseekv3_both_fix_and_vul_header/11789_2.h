#include <limits.h>

typedef struct _GObjectClass {
    void (*finalize)(void*);
    void (*get_property)(void*, int, void*, void*);
    void (*set_property)(void*, int, const void*, void*);
} GObjectClass;

typedef struct _PolkitUnixUserClass {
    GObjectClass parent_class;
} PolkitUnixUserClass;

#define G_OBJECT_CLASS(klass) ((GObjectClass*)klass)
#define G_MININT INT_MIN
#define G_MAXINT INT_MAX

#define G_PARAM_CONSTRUCT (1 << 0)
#define G_PARAM_READWRITE (1 << 1)
#define G_PARAM_STATIC_NAME (1 << 2)
#define G_PARAM_STATIC_BLURB (1 << 3)
#define G_PARAM_STATIC_NICK (1 << 4)

enum {
    PROP_UID,
    N_PROPERTIES
};

void g_object_class_install_property(GObjectClass*, int, void*);
void* g_param_spec_int(const char*, const char*, const char*, int, int, int, int);

void polkit_unix_user_finalize(void*);
void polkit_unix_user_get_property(void*, int, void*, void*);
void polkit_unix_user_set_property(void*, int, const void*, void*);