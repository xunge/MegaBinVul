#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define ARCHIVE_OK 0
#define ARCHIVE_EOF 1
#define AE_IFDIR 0040000
#define AE_IFREG 0100000
#define AE_IFLNK 0120000
#define G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME "standard::display-name"
#define G_FILE_ATTRIBUTE_TIME_MODIFIED "time::modified"
#define G_FILE_QUERY_INFO_NONE 0
#define G_FILE_CREATE_REPLACE_DESTINATION 0
#define G_IO_ERROR 0
#define G_IO_ERROR_NOT_FOUND 0
#define G_IO_ERROR_EXISTS 0
#define G_IO_ERROR_FAILED 0
#define TRUE 1
#define FALSE 0
#define GINT_TO_POINTER(i) ((void*)(intptr_t)(i))

typedef bool gboolean;
typedef size_t gsize;
typedef int (*GEqualFunc)(const void*, const void*);
typedef unsigned int (*GHashFunc)(const void*);
typedef unsigned int __LA_MODE_T;
typedef int64_t __LA_INT64_T;

typedef struct {
    void* destination;
    char* base_dir;
    int junk_paths;
    int overwrite;
    int skip_older;
    void* file_list;
    int n_files_to_extract;
} ExtractData;

typedef struct {
    void* parent_instance;
    void* archive;
    void* error;
} LoadData;

#define LOAD_DATA(obj) ((LoadData*)(obj))

typedef struct {
    int tv_sec;
} GTimeVal;

typedef void GObject;
typedef void GSimpleAsyncResult;
typedef void GCancellable;
typedef void GFile;
typedef void GFileInfo;
typedef void GOutputStream;
typedef void GError;
typedef void GHashTable;

typedef struct archive archive;
typedef struct archive_entry archive_entry;

static unsigned int g_file_hash(const void* p) { return 0; }
static int g_file_equal(const void* a, const void* b) { return 0; }
static void g_object_unref(void* obj) {}
static void* g_simple_async_result_get_op_res_gpointer(void* result) { return NULL; }
static int create_read_object(void* load_data, archive** a) { return 0; }
static void archive_read_free(archive* a) {}
static void* g_hash_table_new_full(GHashFunc hash_func, GEqualFunc key_equal_func, 
                                 void (*key_destroy_func)(void*),
                                 void (*value_destroy_func)(void*)) { return NULL; }
static void fr_archive_progress_set_total_files(void* archive, int n_files) {}
static int archive_read_next_header(archive* a, archive_entry** entry) { return 0; }
static int g_cancellable_is_cancelled(void* cancellable) { return 0; }
static const char* archive_entry_pathname(archive_entry* entry) { return NULL; }
static const char* archive_entry_symlink(archive_entry* entry) { return NULL; }
static int archive_read_data_skip(archive* a) { return 0; }
static char* g_strdup(const char* str) { return NULL; }
static char* g_strconcat(const char* first, ...) { return NULL; }
static char* g_strdup_printf(const char* format, ...) { return NULL; }
static void fr_archive_progress_inc_completed_files(void* archive, int n) {}
static void fr_archive_progress_inc_completed_bytes(void* archive, int64_t n) {}
static int archive_entry_size_is_set(archive_entry* entry) { return 0; }
static int64_t archive_entry_size(archive_entry* entry) { return 0; }
static void* g_file_get_child(void* parent, const char* name) { return NULL; }
static void* g_file_query_info(void* file, const char* attributes, int flags, 
                             void* cancellable, void** error) { return NULL; }
static void g_file_info_get_modification_time(void* info, GTimeVal* time) {}
static time_t archive_entry_mtime(archive_entry* entry) { return 0; }
static void g_clear_error(void** error) {}
static void* g_file_get_parent(void* file) { return NULL; }
static int g_file_query_exists(void* file, void* cancellable) { return 0; }
static void* g_hash_table_lookup(void* hash_table, void* key) { return NULL; }
static void g_hash_table_insert(void* hash_table, void* key, void* value) {}
static void* g_object_ref(void* object) { return NULL; }
static unsigned int archive_entry_filetype(archive_entry* entry) { return 0; }
static const char* archive_entry_hardlink(archive_entry* entry) { return NULL; }
static char* g_file_get_path(void* file) { return NULL; }
static char* g_file_get_uri(void* file) { return NULL; }
static void* g_error_new_literal(int domain, int code, const char* message) { return NULL; }
static void* g_error_copy(void* error) { return NULL; }
static void g_free(void* ptr) {}
static int g_file_make_directory(void* file, void* cancellable, void** error) { return 0; }
static void* g_file_replace(void* file, const char* etag, int make_backup, 
                          int flags, void* cancellable, void** error) { return NULL; }
static int archive_read_data_block(archive* a, const void** buff, size_t* size, 
                                 int64_t* offset) { return 0; }
static int g_output_stream_write_all(void* stream, const void* buffer, size_t count, 
                                   size_t* bytes_written, void* cancellable, 
                                   void** error) { return 0; }
static void _g_object_unref(void* object) {}
static const char* archive_error_string(archive* a) { return NULL; }
static int g_file_make_symbolic_link(void* file, const char* symlink_value, 
                                   void* cancellable, void** error) { return 0; }
static int g_file_delete(void* file, void* cancellable, void** error) { return 0; }
static void g_hash_table_add(void* hash_table, void* key) {}
static void restore_original_file_attributes(void* created_files, void* cancellable) {}
static void g_cancellable_set_error_if_cancelled(void* cancellable, void** error) {}
static void g_simple_async_result_set_from_error(void* result, void* error) {}
static void g_hash_table_unref(void* hash_table) {}
static void extract_data_free(void* extract_data) {}
static int extract_data_get_extraction_requested(ExtractData* data, const char* path) { return 0; }
static const char* _g_path_get_relative_basename_safe(const char* fullpath, const char* base_dir, int junk_paths) { return NULL; }
static int _g_path_is_external_to_destination(const char* path, void* destination, void* links) { return 0; }
static void* _g_file_info_create_from_entry(archive_entry* entry, ExtractData* data) { return NULL; }
static int _g_output_stream_add_padding(ExtractData* data, void* ostream, int64_t target, int64_t actual, void* cancellable, void** error) { return 0; }
static void* _g_error_new_from_archive_error(const char* msg) { return NULL; }
static int _symlink_is_external_to_destination(void* file, const char* symlink, void* destination, void* links) { return 0; }
static int _g_file_make_directory_with_parents(void* parent, void* folders, void* cancellable, void** error) { return 0; }
static int _g_file_contains_symlinks_in_path(const char* path, void* destination, void* symlinks) { return 0; }
static void g_warning(const char* format, ...) {}
static int g_error_matches(void* error, int domain, int code) { return 0; }