#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <strings.h>

typedef bool gboolean;
typedef int gint;
typedef unsigned int guint;
typedef unsigned long gsize;
typedef char gchar;
typedef void* gpointer;
typedef const void* gconstpointer;

struct _GKeyFile;
typedef struct _GKeyFile GKeyFile;

struct _GOutputStream;
typedef struct _GOutputStream GOutputStream;

struct _GCancellable;
typedef struct _GCancellable GCancellable;

struct _GError;
typedef struct _GError GError;

typedef char** GStrv;

struct _GString {
    char *str;
    size_t len;
    size_t allocated_len;
};
typedef struct _GString GString;

struct _GPtrArray {
    gpointer *pdata;
    guint len;
};
typedef struct _GPtrArray GPtrArray;

struct _GHashTable;
typedef struct _GHashTable GHashTable;

#define FALSE false
#define TRUE true
#define g_autofree
#define g_autoptr(x) x*
#define g_auto(x) x*
#define glnx_autofd
#define g_strdup_printf(s, ...) strdup(s)
#define g_key_file_new() NULL
#define g_key_file_load_from_data(k,d,l,f,e) true
#define g_key_file_get_string(k,g,k2,e) NULL
#define g_key_file_set_string_list(k,g,k2,v,l)
#define g_key_file_set_string(k,g,k2,v)
#define g_key_file_get_string_list(k,g,k2,l,e) NULL
#define g_key_file_get_groups(k,l) NULL
#define g_key_file_remove_key(k,g,k2,e)
#define g_key_file_to_data(k,l,e) NULL
#define g_shell_parse_argv(c,a,v,e) true
#define g_string_new(s) calloc(1, sizeof(GString))
#define g_string_append_printf(s,f,...) sprintf((s)->str, f, __VA_ARGS__)
#define g_string_append(s,v) strcat((s)->str, v)
#define g_string_free(s,f) free(s)
#define g_str_has_suffix(s,p) (strstr(s, p) != NULL)
#define g_str_has_prefix(s,p) (strstr(s, p) == s)
#define g_strndup(s,l) strndup(s, l)
#define g_strconcat(...) strdup("")
#define g_strdup(s) strdup(s)
#define g_ptr_array_new_with_free_func(f) calloc(1, sizeof(GPtrArray))
#define g_hash_table_new(h,e) NULL
#define g_hash_table_contains(h,k) false
#define g_hash_table_insert(h,k,v)
#define g_ptr_array_add(a,v)
#define g_steal_pointer(p) NULL
#define g_print(f,...) printf(f, __VA_ARGS__)
#define _(s) s
#define FLATPAK_BINDIR ""
#define FLATPAK_ERROR_EXPORT_FAILED 0
#define G_KEY_FILE_KEEP_TRANSLATIONS 0
#define G_KEY_FILE_DESKTOP_GROUP ""
#define G_KEY_FILE_DESKTOP_KEY_EXEC ""

static bool flatpak_openat_noatime(int parent_fd, const char *name, int *desktop_fd, GCancellable *cancellable, GError **error);
static bool read_fd(int fd, struct stat *stat_buf, char **data, gsize *data_len, GError **error);
static bool flatpak_fail_error(GError **error, int code, const char *format, ...);
static char *maybe_quote(const char *str);
static char *format_flatpak_run_args_from_run_opts(char **opts);
static bool flatpak_open_in_tmpdir_at(int parent_fd, int mode, const char *template, GOutputStream **out_stream, GCancellable *cancellable, GError **error);