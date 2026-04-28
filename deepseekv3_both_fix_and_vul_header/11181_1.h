#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef bool M_bool;
typedef uint32_t M_uint32;
typedef uint64_t M_uint64;

typedef enum {
    M_FS_ERROR_SUCCESS,
    M_FS_ERROR_GENERIC,
    M_FS_ERROR_CANCELED
} M_fs_error_t;

typedef enum {
    M_FS_TYPE_UNKNOWN,
    M_FS_TYPE_DIR,
    M_FS_TYPE_FILE
} M_fs_type_t;

typedef enum {
    M_FS_PATH_NORM_HOME
} M_fs_path_norm_t;

typedef enum {
    M_FS_SYSTEM_AUTO
} M_fs_system_t;

typedef enum {
    M_FS_PATH_INFO_FLAGS_BASIC
} M_fs_path_info_flags_t;

typedef enum {
    M_FS_DIR_WALK_FILTER_ALL = 1 << 0,
    M_FS_DIR_WALK_FILTER_RECURSE = 1 << 1,
    M_FS_DIR_WALK_FILTER_READ_INFO_BASIC = 1 << 2
} M_fs_dir_walk_filter_t;

typedef enum {
    M_FS_PROGRESS_SIZE_TOTAL = 1 << 0,
    M_FS_PROGRESS_SIZE_CUR = 1 << 1,
    M_FS_PROGRESS_COUNT = 1 << 2
} M_fs_progress_flags_t;

typedef struct M_fs_info M_fs_info_t;
typedef struct M_fs_dir_entries M_fs_dir_entries_t;
typedef struct M_fs_dir_entry M_fs_dir_entry_t;
typedef struct M_fs_progress M_fs_progress_t;

typedef M_bool (*M_fs_progress_cb_t)(M_fs_progress_t *progress);

void M_free(void *ptr);