#include <stddef.h>

typedef struct _GKeyfileSettingsBackendClass GKeyfileSettingsBackendClass;
typedef struct _GObjectClass GObjectClass;

struct _GObjectClass {
    void (*finalize)(void);
    void (*constructed)(void);
    void (*get_property)(void);
    void (*set_property)(void);
};

struct _GKeyfileSettingsBackendClass {
    GObjectClass parent_class;
    
    void (*read)(void);
    void (*write)(void);
    void (*write_tree)(void);
    void (*reset)(void);
    void (*get_writable)(void);
    void (*get_permission)(void);
};

void g_keyfile_settings_backend_finalize(void);
void g_keyfile_settings_backend_constructed(void);
void g_keyfile_settings_backend_get_property(void);
void g_keyfile_settings_backend_set_property(void);
void g_keyfile_settings_backend_read(void);
void g_keyfile_settings_backend_write(void);
void g_keyfile_settings_backend_write_tree(void);
void g_keyfile_settings_backend_reset(void);
void g_keyfile_settings_backend_get_writable(void);
void g_keyfile_settings_backend_get_permission(void);

#define G_OBJECT_CLASS(class) ((GObjectClass*)class)
#define P_(str) (str)
#define PROP_FILENAME 1
#define PROP_ROOT_PATH 2
#define PROP_ROOT_GROUP 3
#define G_PARAM_READWRITE (1 << 0)
#define G_PARAM_CONSTRUCT_ONLY (1 << 1)
#define G_PARAM_STATIC_STRINGS (1 << 2)

typedef unsigned int guint;
typedef char gchar;
typedef unsigned int GParamFlags;

typedef struct {
    const gchar *name;
    const gchar *nick;
    const gchar *blurb;
    const gchar *default_value;
    GParamFlags flags;
} GParamSpec;

GParamSpec* g_param_spec_string(const gchar *name, const gchar *nick, const gchar *blurb, const gchar *default_value, GParamFlags flags);
void g_object_class_install_property(GObjectClass *oclass, guint property_id, GParamSpec *pspec);