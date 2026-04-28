#include <stddef.h>

typedef struct _GObjectClass GObjectClass;
typedef struct _GKeyfileSettingsBackendClass GKeyfileSettingsBackendClass;

struct _GObjectClass {
    void (*finalize)();
    void (*constructed)();
    void (*get_property)();
    void (*set_property)();
};

struct _GKeyfileSettingsBackendClass {
    GObjectClass parent_class;
    
    void (*read)();
    void (*write)();
    void (*write_tree)();
    void (*reset)();
    void (*get_writable)();
    void (*get_permission)();
};

#define G_OBJECT_CLASS(klass) ((GObjectClass*)klass)
#define P_(str) str
#define G_PARAM_READWRITE 0
#define G_PARAM_CONSTRUCT_ONLY 0
#define G_PARAM_STATIC_STRINGS 0

enum {
    PROP_FILENAME,
    PROP_ROOT_PATH,
    PROP_ROOT_GROUP,
    PROP_DEFAULTS_DIR
};

void g_keyfile_settings_backend_finalize();
void g_keyfile_settings_backend_constructed();
void g_keyfile_settings_backend_get_property();
void g_keyfile_settings_backend_set_property();
void g_keyfile_settings_backend_read();
void g_keyfile_settings_backend_write();
void g_keyfile_settings_backend_write_tree();
void g_keyfile_settings_backend_reset();
void g_keyfile_settings_backend_get_writable();
void g_keyfile_settings_backend_get_permission();
void g_object_class_install_property(GObjectClass*, int, void*);
void* g_param_spec_string(const char*, const char*, const char*, const char*, int);