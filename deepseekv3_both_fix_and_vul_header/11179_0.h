#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef enum {
    M_FS_ERROR_SUCCESS,
    M_FS_ERROR_GENERIC
} M_fs_error_t;

typedef enum {
    M_FS_SYSTEM_WINDOWS,
    M_FS_SYSTEM_UNIX
} M_fs_system_t;

#define M_FS_FILE_MODE_READ  (1 << 0)
#define M_FS_FILE_MODE_WRITE (1 << 1)

#define M_FS_PATH_NORM_ABSOLUTE (1 << 0)

char *M_strdup(const char *str);
int M_str_isempty(const char *str);
void M_free(void *ptr);
void *M_malloc_zero(size_t size);
size_t M_fs_path_get_path_max(M_fs_system_t sys_type);
M_fs_error_t M_fs_perms_can_access(const char *path, int mode);
M_fs_error_t M_fs_path_norm(char **out, const char *path, int flags, M_fs_system_t sys_type);
#ifdef __APPLE__
char *M_fs_path_mac_tmpdir(void);
#endif