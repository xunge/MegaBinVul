#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct _GObject GObject;
typedef struct _GValue GValue;
typedef struct _GParamSpec GParamSpec;
typedef struct _GFile GFile;

typedef enum {
  PROP_FILENAME,
  PROP_ROOT_PATH,
  PROP_ROOT_GROUP,
  PROP_DEFAULTS_DIR
} GKeyfileSettingsBackendProperty;

typedef struct _GKeyfileSettingsBackend {
  GObject *parent_instance;
  GFile *file;
  char *prefix;
  size_t prefix_len;
  char *root_group;
  size_t root_group_len;
  char *defaults_dir;
} GKeyfileSettingsBackend;

#define G_TYPE_KEYFILE_SETTINGS_BACKEND (0)
#define G_KEYFILE_SETTINGS_BACKEND(obj) ((GKeyfileSettingsBackend*)(obj))

#define g_assert(expr) ((void)0)
#define G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, id, spec) ((void)0)

typedef uint32_t guint;

static inline GFile* g_file_new_for_path(const char *path) { return NULL; }
static inline char* g_value_dup_string(const GValue *value) { return NULL; }
static inline const char* g_value_get_string(const GValue *value) { return NULL; }