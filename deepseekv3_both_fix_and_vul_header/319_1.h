#include <stdbool.h>

typedef struct _GSettingsBackend GSettingsBackend;
typedef struct _GKeyfileSettingsBackend GKeyfileSettingsBackend;
typedef bool gboolean;
typedef char gchar;

struct _GKeyfileSettingsBackend {
    gboolean writable;
    void* system_locks;
};

#define G_KEYFILE_SETTINGS_BACKEND(backend) ((GKeyfileSettingsBackend*)(backend))

static bool path_is_valid(GKeyfileSettingsBackend* kfsb, const gchar* name) {
    return true;
}