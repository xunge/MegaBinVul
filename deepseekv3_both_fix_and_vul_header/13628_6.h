#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#define TRUE true
#define FALSE false
#define G_FILE_TEST_EXISTS 1

typedef void (*GDestroyNotify)(void* data);

typedef void DBusGMethodInvocation;
typedef char gchar;
typedef unsigned int guint;
typedef void* gpointer;
typedef bool gboolean;
typedef int gint;

typedef struct _Daemon Daemon;

typedef struct {
    Daemon *daemon;
    char *id_usage;
    char *device_file;
    char *id_type;
    bool device_is_mounted;
    char *id_label;
    char *id_uuid;
} DevicePrivate;

typedef struct {
    DevicePrivate *priv;
} Device;

typedef struct _FSMountOptions FSMountOptions;
typedef struct _GError GError;

typedef struct {
    char *data;
    size_t len;
    size_t allocated_len;
} GString;

typedef enum {
    ERROR_FAILED,
    ERROR_INVALID_OPTION
} ErrorCode;

typedef struct {
    char *mount_point;
    gboolean remove_dir_on_unmount;
} FilesystemMountData;

static void throw_error(DBusGMethodInvocation *context, ErrorCode error, const char *message, ...) {}
static gboolean is_allowed_filesystem(const gchar *filesystem_type) { return TRUE; }
static void daemon_local_get_uid(Daemon *daemon, uid_t *caller_uid, DBusGMethodInvocation *context) {}
static gboolean device_local_is_busy(Device *device, gboolean check_swap, GError **error) { return FALSE; }
static gboolean is_device_in_fstab(Device *device, char **mount_point) { return FALSE; }
static const FSMountOptions *find_mount_options_for_fs(const char *fstype) { return NULL; }
static char **prepend_default_mount_options(Device *device, const FSMountOptions *fsmo, uid_t caller_uid, gchar **given_options) { return NULL; }
static gboolean is_mount_option_allowed(const FSMountOptions *fsmo, const char *option, uid_t caller_uid) { return TRUE; }
static void mount_file_add(const char *device_file, const char *mount_point, uid_t caller_uid, gboolean remove_dir_on_unmount) {}
static void mount_file_remove(const char *device_file, const char *mount_point) {}
static gboolean job_new(DBusGMethodInvocation *context, const char *job_name, gboolean interactive, Device *device, char **argv, char **envp, void (*completed_cb)(), gboolean wait, FilesystemMountData *data, GDestroyNotify data_free_func) { return TRUE; }
static FilesystemMountData *filesystem_mount_data_new(char *mount_point, gboolean remove_dir_on_unmount) { return NULL; }
static void filesystem_mount_data_free(FilesystemMountData *data) {}
static void filesystem_mount_completed_cb() {}

GString *g_string_new(const char *init) { return NULL; }
char *g_string_free(GString *string, gboolean free_segment) { return NULL; }
void g_string_append_c(GString *string, char c) {}
void g_string_append(GString *string, const char *val) {}
char *g_strdup(const char *str) { return NULL; }
void g_free(void *ptr) {}
char *g_strdup_printf(const char *format, ...) { return NULL; }
gboolean g_file_test(const char *filename, int test) { return FALSE; }
int g_mkdir(const char *filename, int mode) { return 0; }
int g_rmdir(const char *filename) { return 0; }
void g_strfreev(char **str_array) {}
void g_print(const char *format, ...) {}
void g_warning(const char *format, ...) {}
int g_strcmp0(const char *str1, const char *str2) { return 0; }
void g_error_free(GError *error) {}
void dbus_g_method_return_error(DBusGMethodInvocation *context, GError *error) {}