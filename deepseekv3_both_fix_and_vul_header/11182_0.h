#include <stddef.h>

typedef unsigned int M_uint32;
typedef unsigned long long M_uint64;
typedef int M_bool;

#define M_TRUE 1
#define M_FALSE 0

typedef enum {
    M_FS_ERROR_SUCCESS,
    M_FS_ERROR_INVALID,
    M_FS_ERROR_FILE_EXISTS,
    M_FS_ERROR_NOT_SAMEDEV,
    M_FS_ERROR_GENERIC,
    M_FS_ERROR_CANCELED
} M_fs_error_t;

typedef enum {
    M_FS_TYPE_SYMLINK
} M_fs_type_t;

typedef enum {
    M_FS_PATH_NORM_RESDIR,
    M_FS_PATH_NORM_RESALL
} M_fs_path_norm_t;

typedef enum {
    M_FS_SYSTEM_AUTO
} M_fs_system_t;

typedef enum {
    M_FS_PATH_INFO_FLAGS_NONE,
    M_FS_PATH_INFO_FLAGS_BASIC
} M_fs_path_info_flags_t;

typedef enum {
    M_FS_PROGRESS_NOEXTRA
} M_fs_progress_flags_t;

typedef enum {
    M_FS_FILE_MODE_PRESERVE_PERMS,
    M_FS_FILE_MODE_OVERWRITE
} M_fs_file_mode_t;

typedef enum {
    M_FS_PROGRESS_SIZE_TOTAL,
    M_FS_PROGRESS_SIZE_CUR,
    M_FS_PROGRESS_COUNT
} M_fs_progress_flag_t;

typedef struct M_fs_info M_fs_info_t;
typedef struct M_fs_progress M_fs_progress_t;

typedef M_bool (*M_fs_progress_cb_t)(M_fs_progress_t *progress);

M_fs_error_t M_fs_path_norm(char **norm_path, const char *path, M_fs_path_norm_t norm_type, M_fs_system_t sys_type);
M_bool M_fs_isfileintodir(const char *path_old, const char *path_new, char **norm_path_old);
M_fs_error_t M_fs_info(M_fs_info_t **info, const char *path, M_fs_path_info_flags_t flags);
M_uint64 M_fs_info_get_size(const M_fs_info_t *info);
M_fs_type_t M_fs_info_get_type(const M_fs_info_t *info);
void M_fs_info_destroy(M_fs_info_t *info);
M_fs_progress_t *M_fs_progress_create(void);
void M_fs_progress_destroy(M_fs_progress_t *progress);
void M_fs_progress_set_path(M_fs_progress_t *progress, const char *path);
void M_fs_progress_set_type(M_fs_progress_t *progress, M_fs_type_t type);
void M_fs_progress_set_size_total(M_fs_progress_t *progress, M_uint64 size);
void M_fs_progress_set_size_total_progess(M_fs_progress_t *progress, M_uint64 size);
void M_fs_progress_set_size_current(M_fs_progress_t *progress, M_uint64 size);
void M_fs_progress_set_size_current_progress(M_fs_progress_t *progress, M_uint64 size);
void M_fs_progress_set_count_total(M_fs_progress_t *progress, M_uint32 count);
void M_fs_progress_set_count(M_fs_progress_t *progress, M_uint32 count);
void M_fs_progress_set_result(M_fs_progress_t *progress, M_fs_error_t res);
M_bool M_fs_check_overwrite_allowed(const char *path_old, const char *path_new, M_uint32 mode);
M_fs_error_t M_fs_path_readlink(char **resolve_path, const char *path);
M_fs_error_t M_fs_symlink(const char *path, const char *target);
M_fs_error_t M_fs_move_file(const char *path_old, const char *path_new);
M_fs_error_t M_fs_copy(const char *path_old, const char *path_new, M_uint32 mode, M_fs_progress_cb_t cb, M_uint32 progress_flags);
M_fs_error_t M_fs_delete(const char *path, M_bool recursive, M_fs_progress_cb_t cb, M_fs_progress_flags_t flags);
void M_free(void *ptr);