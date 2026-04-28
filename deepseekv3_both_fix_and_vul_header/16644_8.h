#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <locale.h>
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#define FLATPAK_BINDIR "/usr/bin"
#define FLATPAK_ERROR_EXPORT_FAILED 0
#define G_KEY_FILE_DESKTOP_GROUP "Desktop Entry"
#define G_KEY_FILE_DESKTOP_KEY_EXEC "Exec"
#define G_KEY_FILE_KEEP_TRANSLATIONS 0
#define TRUE 1
#define FALSE 0

typedef int gboolean;
typedef void* gpointer;
typedef const void* gconstpointer;
typedef char gchar;
typedef char** GStrv;
typedef int gint;
typedef size_t gsize;

struct _GKeyFile;
typedef struct _GKeyFile GKeyFile;

struct _GOutputStream;
typedef struct _GOutputStream GOutputStream;

struct _GCancellable;
typedef struct _GCancellable GCancellable;

struct _GError;
typedef struct _GError GError;

struct _GString {
    char* str;
    size_t len;
    size_t allocated_len;
};
typedef struct _GString GString;

struct _GPtrArray {
    void** pdata;
    unsigned int len;
    unsigned int alloc;
};
typedef struct _GPtrArray GPtrArray;

struct _GHashTable;
typedef struct _GHashTable GHashTable;

/* Function prototypes */
GString* g_string_new(const char* str);
void g_string_free(GString* string, gboolean free_segment);
void g_string_append(GString* string, const char* val);
void g_string_append_printf(GString* string, const char* format, ...);

char* g_strdup_printf(const char* format, ...);
char* g_strndup(const char* str, size_t n);
char* g_strconcat(const char* first, ...);
gboolean g_str_has_suffix(const char* str, const char* suffix);
gboolean g_str_has_prefix(const char* str, const char* prefix);
unsigned int g_str_hash(gconstpointer v);
gboolean g_str_equal(gconstpointer v1, gconstpointer v2);

GKeyFile* g_key_file_new(void);
gboolean g_key_file_load_from_data(GKeyFile* keyfile, const char* data, size_t length, int flags, GError** error);
char* g_key_file_get_string(GKeyFile* keyfile, const char* group_name, const char* key, GError** error);
char** g_key_file_get_string_list(GKeyFile* keyfile, const char* group_name, const char* key, size_t* length, GError** error);
void g_key_file_set_string_list(GKeyFile* keyfile, const char* group_name, const char* key, const char* const list[], size_t length);
void g_key_file_set_string(GKeyFile* keyfile, const char* group_name, const char* key, const char* string);
char** g_key_file_get_groups(GKeyFile* keyfile, size_t* length);
void g_key_file_remove_key(GKeyFile* keyfile, const char* group_name, const char* key, GError** error);
char* g_key_file_to_data(GKeyFile* keyfile, size_t* length, GError** error);

gboolean g_shell_parse_argv(const char* command_line, int* argcp, char*** argvp, GError** error);
gboolean g_output_stream_write_all(GOutputStream* stream, const void* buffer, size_t count, size_t* bytes_written, GCancellable* cancellable, GError** error);
gboolean g_output_stream_close(GOutputStream* stream, GCancellable* cancellable, GError** error);

gboolean flatpak_openat_noatime(int parent_fd, const char* name, int* out_fd, GCancellable* cancellable, GError** error);
gboolean read_fd(int fd, struct stat* stat_buf, char** data, size_t* data_len, GError** error);
gboolean flatpak_fail_error(GError** error, int code, const char* format, ...);
gboolean flatpak_open_in_tmpdir_at(int parent_fd, int mode, const char* tmpl, GOutputStream** out_stream, GCancellable* cancellable, GError** error);
char* maybe_quote(const char* str);
char* format_flatpak_run_args_from_run_opts(char** run_opts);

GPtrArray* g_ptr_array_new_with_free_func(void (*free_func)(gpointer));
void g_ptr_array_add(GPtrArray* array, gpointer data);
GHashTable* g_hash_table_new(unsigned int (*hash_func)(gconstpointer key), gboolean (*key_equal_func)(gconstpointer a, gconstpointer b));
gboolean g_hash_table_contains(GHashTable* hash_table, gconstpointer key);
void g_hash_table_insert(GHashTable* hash_table, gpointer key, gpointer value);
void g_free(gpointer mem);
void* g_steal_pointer(void* pp);
#define g_assert(expr) assert(expr)

void g_print(const char* format, ...);
#define _(x) x

/* Replace GLib macros with standard variable declarations */
#define glnx_autofd
#define g_autofree
#define g_autoptr(x)
#define g_auto(x)

/* Variable declarations */
int desktop_fd = -1;
char *tmpfile_name = NULL;
GOutputStream *out_stream = NULL;
gchar *data = NULL;
gsize data_len = 0;
gchar *new_data = NULL;
gsize new_data_len = 0;
GKeyFile *keyfile = NULL;
gchar *old_exec = NULL;
gint old_argc = 0;
GStrv old_argv = NULL;
GStrv groups = NULL;
GString *new_exec = NULL;
char *escaped_app = NULL;
char *escaped_branch = NULL;
char *escaped_arch = NULL;
gsize length = 0;
GStrv tags = NULL;
GStrv renamed_from = NULL;
GPtrArray *merged = NULL;
GHashTable *seen = NULL;
const char *new_suffix = NULL;
GStrv flatpak_run_opts = NULL;
char *flatpak_run_args = NULL;
char *command = NULL;
char *arg = NULL;
gchar *dbus_name = NULL;
gchar *expected_dbus_name = NULL;
gchar *previous_desktop = NULL;