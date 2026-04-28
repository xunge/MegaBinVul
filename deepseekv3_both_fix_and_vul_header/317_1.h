#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct _GObject GObject;
typedef struct _GValue GValue;
typedef struct _GParamSpec GParamSpec;
typedef struct _GFile GFile;

typedef uint32_t guint;

typedef struct _GKeyfileSettingsBackend GKeyfileSettingsBackend;
struct _GKeyfileSettingsBackend {
    GFile *file;
    char *prefix;
    char *root_group;
    char *defaults_dir;
};

#define G_KEYFILE_SETTINGS_BACKEND(obj) ((GKeyfileSettingsBackend*)obj)
#define G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, id, spec)

typedef enum {
    PROP_FILENAME,
    PROP_ROOT_PATH,
    PROP_ROOT_GROUP,
    PROP_DEFAULTS_DIR
} GKeyfileSettingsBackendProperty;

void g_value_set_string(GValue *value, const char *str);
const char *g_file_peek_path(GFile *file);