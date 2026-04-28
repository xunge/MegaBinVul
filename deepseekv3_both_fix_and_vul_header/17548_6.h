#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARCHIVE_OK 0
#define ARCHIVE_EOF 1
#define AE_IFDIR 0040000
#define AE_IFREG 0100000
#define AE_IFLNK 0120000
#define FALSE 0
#define TRUE 1
#define G_IO_ERROR 1
#define G_IO_ERROR_NOT_FOUND 2
#define G_IO_ERROR_EXISTS 3
#define G_IO_ERROR_FAILED 4
#define G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME "standard::display-name"
#define G_FILE_ATTRIBUTE_TIME_MODIFIED "time::modified"
#define G_FILE_CREATE_REPLACE_DESTINATION 0
#define G_FILE_QUERY_INFO_NONE 0
#define GINT_TO_POINTER(i) ((void*)(long)(i))

typedef int gboolean;
typedef void* gpointer;
typedef const void* gconstpointer;
typedef unsigned int guint;
typedef int64_t gint64;
typedef size_t gsize;

struct archive;
struct archive_entry;

typedef int __LA_MODE_T;
typedef int64_t __LA_INT64_T;

typedef struct {
    long tv_sec;
    long tv_usec;
} GTimeVal;

typedef struct {
    void* unused;
} GObject;

typedef struct {
    int domain;
    int code;
    char* message;
} GError;

typedef struct {
    GObject parent;
    void* archive;
    GError* error;
} LoadData;

typedef struct {
    GObject parent;
    char* base_dir;
    char* junk_paths;
    void* destination;
    int n_files_to_extract;
    void* file_list;
    gboolean skip_older;
    gboolean overwrite;
} ExtractData;

typedef struct {
    /* Minimal definition */
} GSimpleAsyncResult;
typedef struct {
    /* Minimal definition */ 
} GCancellable;
typedef struct {
    /* Minimal definition */
} GHashTable;
typedef struct {
    /* Minimal definition */
} GFile;
typedef struct {
    /* Minimal definition */
} GFileInfo;
typedef struct {
    /* Minimal definition */
} GOutputStream;

#define LOAD_DATA(obj) ((LoadData*)(obj))

typedef guint (*GHashFunc)(gconstpointer key);
typedef gboolean (*GEqualFunc)(gconstpointer a, gconstpointer b);

static guint g_file_hash(gconstpointer key) { return 0; }
static gboolean g_file_equal(gconstpointer a, gconstpointer b) { return FALSE; }
static void g_object_unref(gpointer object) {}
static void* g_simple_async_result_get_op_res_gpointer(GSimpleAsyncResult *result) { return NULL; }
static int create_read_object(LoadData *load_data, struct archive **a) { return 0; }
static void archive_read_free(struct archive *a) {}
static GHashTable* g_hash_table_new_full(GHashFunc hash_func, GEqualFunc key_equal_func, 
                                        void (*key_destroy_func)(gpointer), 
                                        void (*value_destroy_func)(gpointer)) { return NULL; }
static void fr_archive_progress_set_total_files(void *archive, int n_files) {}
static int archive_read_next_header(struct archive *a, struct archive_entry **entry) { return 0; }
static gboolean g_cancellable_is_cancelled(GCancellable *cancellable) { return FALSE; }
static const char* archive_entry_pathname(struct archive_entry *entry) { return NULL; }
static gboolean extract_data_get_extraction_requested(ExtractData *extract_data, const char *pathname) { return FALSE; }
static void archive_read_data_skip(struct archive *a) {}
static char* g_strdup(const char *str) { return NULL; }
static char* g_strconcat(const char *string1, ...) { return NULL; }
static const char* _g_path_get_relative_basename_safe(const char *fullpath, const char *base_dir, const char *junk_paths) { return NULL; }
static GFile* g_file_get_child(void *parent, const char *name) { return NULL; }
static gpointer g_hash_table_lookup(GHashTable *hash_table, gconstpointer key) { return NULL; }
static GFileInfo* g_file_query_info(GFile *file, const char *attributes, int flags, 
                                  GCancellable *cancellable, GError **error) { return NULL; }
static void g_file_info_get_modification_time(GFileInfo *info, GTimeVal *modification_time) {}
static time_t archive_entry_mtime(struct archive_entry *entry) { return 0; }
static gboolean archive_entry_size_is_set(struct archive_entry *entry) { return FALSE; }
static int64_t archive_entry_size(struct archive_entry *entry) { return 0; }
static void fr_archive_progress_inc_completed_bytes(void *archive, int64_t bytes) {}
static gboolean g_error_matches(const GError *error, int domain, int code) { return FALSE; }
static void g_clear_error(GError **error) {}
static void fr_archive_progress_inc_completed_files(void *archive, int files) {}
static GFile* g_file_get_parent(GFile *file) { return NULL; }
static gboolean g_file_query_exists(GFile *file, GCancellable *cancellable) { return FALSE; }
static gboolean _g_file_make_directory_with_parents(GFile *parent, GHashTable *folders, 
                                                   GCancellable *cancellable, GError **error) { return FALSE; }
static GFile* g_object_ref(gpointer object) { return NULL; }
static void g_hash_table_insert(GHashTable *hash_table, gpointer key, gpointer value) {}
static __LA_MODE_T archive_entry_filetype(struct archive_entry *entry) { return 0; }
static const char* archive_entry_hardlink(struct archive_entry *entry) { return NULL; }
static void g_free(gpointer mem) {}
static char* g_file_get_path(GFile *file) { return NULL; }
static char* g_file_get_uri(GFile *file) { return NULL; }
static char* g_strdup_printf(const char *format, ...) { return NULL; }
static GError* g_error_new_literal(int domain, int code, const char *message) { return NULL; }
static gboolean g_file_make_directory(GFile *file, GCancellable *cancellable, GError **error) { return FALSE; }
static GError* g_error_copy(GError *error) { return NULL; }
static void* _g_file_info_create_from_entry(struct archive_entry *entry, ExtractData *extract_data) { return NULL; }
static GOutputStream* g_file_replace(GFile *file, const char *etag, gboolean make_backup, 
                                   int flags, GCancellable *cancellable, GError **error) { return NULL; }
static int archive_read_data_block(struct archive *a, const void **buff, size_t *size, int64_t *offset) { return 0; }
static gboolean _g_output_stream_add_padding(ExtractData *extract_data, GOutputStream *stream, 
                                           int64_t target_offset, int64_t actual_offset, 
                                           GCancellable *cancellable, GError **error) { return FALSE; }
static gboolean g_output_stream_write_all(GOutputStream *stream, const void *buffer, size_t count, 
                                        size_t *bytes_written, GCancellable *cancellable, 
                                        GError **error) { return FALSE; }
static void _g_object_unref(gpointer object) {}
static GError* _g_error_new_from_archive_error(const char *error_string) { return NULL; }
static const char* archive_error_string(struct archive *a) { return NULL; }
static gboolean g_file_make_symbolic_link(GFile *file, const char *symlink_value, 
                                        GCancellable *cancellable, GError **error) { return FALSE; }
static const char* archive_entry_symlink(struct archive_entry *entry) { return NULL; }
static void restore_original_file_attributes(GHashTable *created_files, GCancellable *cancellable) {}
static void g_cancellable_set_error_if_cancelled(GCancellable *cancellable, GError **error) {}
static void g_simple_async_result_set_from_error(GSimpleAsyncResult *result, GError *error) {}
static void g_hash_table_unref(GHashTable *hash_table) {}
static void extract_data_free(ExtractData *extract_data) {}