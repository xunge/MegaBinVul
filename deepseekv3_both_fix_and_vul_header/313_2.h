#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define TRUE 1
#define FALSE 0
#define G_FILE_MONITOR_NONE 0

typedef struct _GObject GObject;
typedef struct _GFile GFile;
typedef struct _GKeyFile GKeyFile;
typedef struct _GPermission GPermission;
typedef struct _GFileMonitor GFileMonitor;

typedef struct _GKeyfileSettingsBackend GKeyfileSettingsBackend;
struct _GKeyfileSettingsBackend {
    GFile *file;
    char *prefix;
    size_t prefix_len;
    GKeyFile *keyfile;
    GPermission *permission;
    GFile *dir;
    GFileMonitor *file_monitor;
    GFileMonitor *dir_monitor;
    unsigned char digest[16];
};

#define G_KEYFILE_SETTINGS_BACKEND(obj) ((GKeyfileSettingsBackend*)obj)
#define G_CALLBACK(f) ((void*)(f))

char* g_build_filename(const char* first, ...);
char* g_get_user_config_dir(void);
GFile* g_file_new_for_path(const char* path);
void g_free(void* ptr);
char* g_strdup(const char* str);
GKeyFile* g_key_file_new(void);
GPermission* g_simple_permission_new(int allowed);
GFile* g_file_get_parent(GFile* file);
int g_mkdir_with_parents(const char* path, int mode);
const char* g_file_peek_path(GFile* file);
GFileMonitor* g_file_monitor(GFile* file, int flags, void* cancellable, void* error);
void g_signal_connect(GFileMonitor* monitor, const char* signal, void* callback, void* user_data);
void g_file_make_directory_with_parents(GFile* dir, void* cancellable, void* error);

void compute_checksum(unsigned char* digest, const unsigned char* data, size_t len);
void file_changed(GFileMonitor* monitor, GFile* file, GFile* other_file, int event_type, void* user_data);
void dir_changed(GFileMonitor* monitor, GFile* file, GFile* other_file, int event_type, void* user_data);
void g_keyfile_settings_backend_keyfile_writable(GKeyfileSettingsBackend* kfsb);
void g_keyfile_settings_backend_keyfile_reload(GKeyfileSettingsBackend* kfsb);
void load_system_settings(GKeyfileSettingsBackend* kfsb);