#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef void* GSimpleAsyncResult;
typedef void* GObject;
typedef void* GCancellable;
typedef void* GHashTable;
typedef void* GFile;
typedef void* GOutputStream;
typedef void* GError;
typedef void* GFileInfo;

typedef struct {
    GFile *destination;
    char *base_dir;
    int junk_paths;
    int skip_older;
    int overwrite;
    void *file_list;
    int n_files_to_extract;
} ExtractData;

typedef struct {
    void *archive;
    GError *error;
} LoadData;

#define LOAD_DATA(obj) ((LoadData *)obj)

typedef struct archive archive;
typedef struct archive_entry archive_entry;

#define ARCHIVE_OK 0
#define ARCHIVE_EOF 1
#define AE_IFDIR 0040000
#define AE_IFREG 0100000
#define AE_IFLNK 0120000

typedef int64_t __LA_INT64_T;
typedef mode_t __LA_MODE_T;

typedef struct {
    int tv_sec;
} GTimeVal;

typedef int gboolean;
#define FALSE 0
#define TRUE 1

#define G_IO_ERROR 0
#define G_IO_ERROR_NOT_FOUND 1
#define G_IO_ERROR_EXISTS 2
#define G_IO_ERROR_FAILED 3
#define FR_ERROR 0
#define FR_ERROR_COMMAND_ERROR 1
#define G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME ""
#define G_FILE_ATTRIBUTE_TIME_MODIFIED ""
#define G_FILE_QUERY_INFO_NONE 0
#define G_FILE_CREATE_REPLACE_DESTINATION 0

typedef unsigned int (*GHashFunc)(const void*);
typedef int (*GEqualFunc)(const void*, const void*);
#define GINT_TO_POINTER(i) ((void*)(long)(i))

static int load_data_open(struct archive* a, void* client_data) { return 0; }
static ssize_t load_data_read(struct archive* a, void* client_data, const void** buff) { return 0; }
static int load_data_close(struct archive* a, void* client_data) { return 0; }

static unsigned int g_file_hash(const void* p) { return 0; }
static int g_file_equal(const void* a, const void* b) { return 0; }
static void g_object_unref(void* obj) {}
static void* g_simple_async_result_get_op_res_gpointer(void* result) { return NULL; }
static void* g_hash_table_new_full(GHashFunc hash_func, GEqualFunc key_equal_func, void* destroy_key, void* destroy_value) { return NULL; }
static void fr_archive_progress_set_total_files(void* archive, int n_files) {}
static struct archive* archive_read_new(void) { return NULL; }
static int archive_read_support_filter_all(struct archive* a) { return 0; }
static int archive_read_support_format_all(struct archive* a) { return 0; }
static int archive_read_open(struct archive* a, void* client_data, int (*open_cb)(struct archive*, void*), ssize_t (*read_cb)(struct archive*, void*, const void**), int (*close_cb)(struct archive*, void*)) { return 0; }
static int archive_read_next_header(struct archive* a, struct archive_entry** entry) { return 0; }
static int g_cancellable_is_cancelled(void* cancellable) { return 0; }
static const char* archive_entry_pathname(struct archive_entry* entry) { return NULL; }
static int extract_data_get_extraction_requested(ExtractData* data, const char* path) { return 0; }
static int archive_read_data_skip(struct archive* a) { return 0; }
static char* g_strdup(const char* str) { return NULL; }
static char* g_strconcat(const char* first, ...) { return NULL; }
static void* g_file_get_child(void* parent, const char* name) { return NULL; }
static char* _g_path_get_relative_basename(const char* fullpath, const char* base_dir, int junk_paths) { return NULL; }
static void* g_file_query_info(void* file, const char* attributes, int flags, void* cancellable, void** error) { return NULL; }
static void g_file_info_get_modification_time(void* info, GTimeVal* time) {}
static time_t archive_entry_mtime(struct archive_entry* entry) { return 0; }
static void g_error_free(void* error) {}
static int g_error_matches(void* error, int domain, int code) { return 0; }
static void fr_archive_progress_inc_completed_files(void* archive, int n) {}
static void* g_file_get_parent(void* file) { return NULL; }
static void* g_hash_table_lookup(void* hash_table, const void* key) { return NULL; }
static int g_file_query_exists(void* file, void* cancellable) { return 0; }
static int g_file_make_directory_with_parents(void* file, void* cancellable, void** error) { return 0; }
static void* g_object_ref(void* object) { return NULL; }
static void g_hash_table_insert(void* hash_table, void* key, void* value) {}
static int archive_entry_filetype(struct archive_entry* entry) { return 0; }
static const char* archive_entry_hardlink(struct archive_entry* entry) { return NULL; }
static char* g_file_get_path(void* file) { return NULL; }
static char* g_file_get_uri(void* file) { return NULL; }
static char* g_strdup_printf(const char* format, ...) { return NULL; }
static void* g_error_new_literal(int domain, int code, const char* message) { return NULL; }
static void g_free(void* mem) {}
static int g_file_make_directory(void* file, void* cancellable, void** error) { return 0; }
static void _g_file_set_attributes_from_entry(void* file, struct archive_entry* entry, ExtractData* data, void* cancellable) {}
static void* g_file_replace(void* file, const char* etag, gboolean make_backup, int flags, void* cancellable, void** error) { return NULL; }
static int archive_read_data_block(struct archive* a, const void** buff, size_t* size, int64_t* offset) { return 0; }
static int g_output_stream_write(void* stream, const void* buffer, size_t count, void* cancellable, void** error) { return 0; }
static void _g_object_unref(void* object) {}
static const char* archive_error_string(struct archive* a) { return NULL; }
static int g_file_make_symbolic_link(void* file, const char* symlink_value, void* cancellable, void** error) { return 0; }
static const char* archive_entry_symlink(struct archive_entry* entry) { return NULL; }
static void* g_error_copy(void* error) { return NULL; }
static void g_cancellable_set_error_if_cancelled(void* cancellable, void** error) {}
static void g_simple_async_result_set_from_error(void* result, void* error) {}
static void g_hash_table_unref(void* hash_table) {}
static void archive_read_free(struct archive* a) {}
static void extract_data_free(ExtractData* data) {}
static int archive_entry_size_is_set(struct archive_entry* entry) { return 0; }
static int64_t archive_entry_size(struct archive_entry* entry) { return 0; }
static void fr_archive_progress_inc_completed_bytes(void* archive, int64_t bytes) {}