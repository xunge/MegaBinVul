#include <stddef.h>
#include <stdint.h>

typedef unsigned int M_uint32;
typedef unsigned long long M_uint64;

#define M_FALSE 0
#define M_TRUE 1
#define M_FS_BUF_SIZE 8192

typedef enum {
    M_FS_ERROR_SUCCESS,
    M_FS_ERROR_INVALID,
    M_FS_ERROR_FILE_EXISTS,
    M_FS_ERROR_CANCELED
} M_fs_error_t;

typedef enum {
    M_FS_TYPE_DIR,
    M_FS_TYPE_SYMLINK,
    M_FS_TYPE_FILE
} M_fs_type_t;

typedef enum {
    M_FS_DIR_WALK_FILTER_ALL = 1,
    M_FS_DIR_WALK_FILTER_RECURSE = 2,
    M_FS_DIR_WALK_FILTER_READ_INFO_BASIC = 4,
    M_FS_DIR_WALK_FILTER_READ_INFO_FULL = 8
} M_fs_dir_walk_filter_t;

typedef enum {
    M_FS_FILE_MODE_PRESERVE_PERMS = 1,
    M_FS_FILE_MODE_OVERWRITE = 2
} M_fs_file_mode_t;

typedef enum {
    M_FS_PATH_NORM_RESDIR,
    M_FS_PATH_NORM_RESALL
} M_fs_path_norm_t;

typedef enum {
    M_FS_SYSTEM_AUTO
} M_fs_system_t;

typedef enum {
    M_FS_DIR_SORT_ISDIR,
    M_FS_DIR_SORT_NAME_CASECMP
} M_fs_dir_sort_t;

typedef enum {
    M_FS_PROGRESS_SIZE_TOTAL = 1,
    M_FS_PROGRESS_SIZE_CUR = 2,
    M_FS_PROGRESS_COUNT = 4,
    M_FS_PROGRESS_NOEXTRA = 8
} M_fs_progress_flags_t;

typedef enum {
    M_FS_PATH_INFO_FLAGS_NONE = 0,
    M_FS_PATH_INFO_FLAGS_BASIC = 1
} M_fs_path_info_flags_t;

typedef struct M_fs_dir_entries_t M_fs_dir_entries_t;
typedef struct M_fs_dir_entry_t M_fs_dir_entry_t;
typedef struct M_fs_info_t M_fs_info_t;
typedef struct M_fs_progress_t M_fs_progress_t;
typedef struct M_fs_perms_t M_fs_perms_t;

typedef int (*M_fs_progress_cb_t)(M_fs_progress_t *);

const M_fs_info_t *M_fs_dir_entry_get_info(const M_fs_dir_entry_t *);
M_fs_type_t M_fs_dir_entry_get_type(const M_fs_dir_entry_t *);
const char *M_fs_dir_entry_get_name(const M_fs_dir_entry_t *);
const char *M_fs_dir_entry_get_resolved_name(const M_fs_dir_entry_t *);

M_fs_dir_entries_t *M_fs_dir_entries_create(void);
void M_fs_dir_entries_destroy(M_fs_dir_entries_t *);
size_t M_fs_dir_entries_len(const M_fs_dir_entries_t *);
const M_fs_dir_entry_t *M_fs_dir_entries_at(const M_fs_dir_entries_t *, size_t);
void M_fs_dir_entries_insert(M_fs_dir_entries_t *, M_fs_dir_entry_t *);
void M_fs_dir_entries_merge(M_fs_dir_entries_t **, M_fs_dir_entries_t *);
void M_fs_dir_entries_sort(M_fs_dir_entries_t *, M_fs_dir_sort_t, int, M_fs_dir_sort_t, int);

M_fs_dir_entry_t *M_fs_dir_walk_fill_entry(const char *, const char *, M_fs_type_t, M_fs_info_t *, M_fs_dir_walk_filter_t);
M_fs_dir_entries_t *M_fs_dir_walk_entries(const char *, const char *, M_fs_dir_walk_filter_t);

M_fs_error_t M_fs_path_norm(char **, const char *, M_fs_path_norm_t, M_fs_system_t);
char *M_fs_path_join(const char *, const char *, M_fs_system_t);

M_fs_error_t M_fs_info(M_fs_info_t **, const char *, M_fs_path_info_flags_t);
M_fs_type_t M_fs_info_get_type(const M_fs_info_t *);
M_uint64 M_fs_info_get_size(const M_fs_info_t *);
M_fs_perms_t *M_fs_info_get_perms(const M_fs_info_t *);

M_fs_progress_t *M_fs_progress_create(void);
void M_fs_progress_destroy(M_fs_progress_t *);
void M_fs_progress_set_path(M_fs_progress_t *, const char *);
void M_fs_progress_set_type(M_fs_progress_t *, M_fs_type_t);
void M_fs_progress_set_result(M_fs_progress_t *, M_fs_error_t);
void M_fs_progress_set_size_total(M_fs_progress_t *, M_uint64);
void M_fs_progress_set_size_current(M_fs_progress_t *, M_uint64);
void M_fs_progress_set_size_total_progess(M_fs_progress_t *, M_uint64);
void M_fs_progress_set_size_current_progress(M_fs_progress_t *, M_uint64);
void M_fs_progress_set_count_total(M_fs_progress_t *, M_uint64);
void M_fs_progress_set_count(M_fs_progress_t *, M_uint64);
M_uint64 M_fs_progress_get_count(const M_fs_progress_t *);

M_fs_error_t M_fs_dir_mkdir(const char *, int, void *);
M_fs_error_t M_fs_symlink(const char *, const char *);
M_fs_error_t M_fs_perms_set_perms(M_fs_perms_t *, const char *);
M_fs_error_t M_fs_copy_file(const char *, const char *, M_uint32, M_fs_progress_cb_t, M_uint32, M_fs_progress_t *, M_fs_perms_t *);
M_fs_error_t M_fs_delete(const char *, int, void *, M_fs_progress_flags_t);

int M_fs_isfileintodir(const char *, const char *, char **);
int M_fs_check_overwrite_allowed(const char *, const char *, M_uint32);

void M_free(void *);