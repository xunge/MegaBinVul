#include <stdint.h>
#include <stddef.h>

typedef unsigned int M_uint32;
typedef int M_bool;
#define M_TRUE 1
#define M_FALSE 0

typedef enum {
    M_FS_TYPE_DIR,
    M_FS_TYPE_FILE
} M_fs_type_t;

typedef enum {
    M_FS_ERROR_SUCCESS,
    M_FS_ERROR_FAILURE
} M_fs_error_t;

typedef enum {
    M_FS_PERMS_MODE_NONE
} M_fs_perms_mode_t;

typedef enum {
    M_FS_PATH_INFO_FLAGS_BASIC
} M_fs_path_info_flags_t;

#define M_FS_FILE_MODE_OVERWRITE (1 << 0)

typedef struct M_fs_info_t M_fs_info_t;

M_fs_error_t M_fs_info(M_fs_info_t **info, const char *path, M_fs_path_info_flags_t flags);
M_fs_type_t M_fs_info_get_type(const M_fs_info_t *info);
void M_fs_info_destroy(M_fs_info_t *info);
M_fs_error_t M_fs_perms_can_access(const char *path, M_fs_perms_mode_t mode);
char *M_fs_path_basename(const char *path, int system);
char *M_fs_path_join(const char *path1, const char *path2, int system);
void M_free(void *ptr);

#define M_FS_SYSTEM_AUTO 0