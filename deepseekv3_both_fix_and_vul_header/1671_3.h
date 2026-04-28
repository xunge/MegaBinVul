#include <stddef.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>

typedef struct _FuPlugin FuPlugin;
typedef struct _GKeyFile GKeyFile;
typedef char gchar;
typedef int gint;
typedef bool gboolean;
typedef ssize_t gssize;
typedef struct _GError GError;

#define FALSE false
#define TRUE true
#define FU_IS_PLUGIN(obj) (obj)
#define FWUPD_ERROR 0
#define FWUPD_ERROR_NOT_FOUND 0
#define FWUPD_ERROR_INTERNAL 0
#define G_FILE_TEST_EXISTS 0
#define G_KEY_FILE_KEEP_COMMENTS 0
#define G_FILE_SET_CONTENTS_CONSISTENT 0

#define g_autofree
#define g_autoptr(type) type* __attribute__((cleanup(g_autoptr_cleanup_##type)))
static inline void g_autoptr_cleanup_GKeyFile(GKeyFile **ptr) { if (*ptr) g_key_file_free(*ptr); }

gchar* fu_plugin_get_config_filename(FuPlugin *self);
gchar* fu_plugin_get_name(FuPlugin *self);
gboolean fu_plugin_set_config_value(FuPlugin *self, const gchar *key, const gchar *value, GError **error);
int g_chmod(const char *path, mode_t mode);
int g_file_test(const char *filename, int test);
void g_set_error(GError **err, int domain, int code, const char *format, ...);
void g_return_val_if_fail(gboolean expr, gboolean val);
GKeyFile* g_key_file_new(void);
gboolean g_key_file_load_from_file(GKeyFile *key_file, const gchar *file, int flags, GError **error);
void g_key_file_set_string(GKeyFile *key_file, const gchar *group_name, const gchar *key, const gchar *value);
gchar* g_key_file_to_data(GKeyFile *key_file, size_t *length, GError **error);
gboolean g_file_set_contents_full(const gchar *filename, const gchar *contents, gssize length, int flags, mode_t mode, GError **error);
void g_key_file_free(GKeyFile *key_file);