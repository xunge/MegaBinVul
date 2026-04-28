#include <stddef.h>
#include <stdbool.h>

typedef enum {
    M_FS_ERROR_SUCCESS,
    M_FS_ERROR_CANCELED
} M_fs_error_t;

typedef unsigned int M_fs_file_mode_t;
typedef unsigned int M_fs_progress_flags_t;

#define M_FS_BUF_SIZE 8192
#define M_FS_FILE_MODE_READ 0x01
#define M_FS_FILE_MODE_WRITE 0x02
#define M_FS_FILE_MODE_OVERWRITE 0x04
#define M_FS_FILE_MODE_NOCREATE 0x08
#define M_FS_FILE_MODE_PRESERVE_PERMS 0x10
#define M_FS_PERMS_MODE_NONE 0
#define M_FS_PROGRESS_NOEXTRA 0
#define M_FS_PATH_INFO_FLAGS_NONE 0
#define M_FS_FILE_RW_NORMAL 0
#define M_FS_PROGRESS_SIZE_TOTAL 0x01
#define M_FS_PROGRESS_SIZE_CUR 0x02
#define M_FS_PROGRESS_COUNT 0x04
#define M_FALSE false

typedef struct M_fs_file_t M_fs_file_t;
typedef struct M_fs_info_t M_fs_info_t;
typedef struct M_fs_progress_t M_fs_progress_t;
typedef struct M_fs_perms_t M_fs_perms_t;

typedef bool (*M_fs_progress_cb_t)(M_fs_progress_t *progress);

M_fs_error_t M_fs_perms_can_access(const char *path, unsigned int mode);
M_fs_error_t M_fs_delete(const char *path, bool recursive, void *unused, unsigned int flags);
M_fs_error_t M_fs_file_open(M_fs_file_t **fd, const char *path, size_t buf_size, M_fs_file_mode_t mode, const M_fs_perms_t *perms);
M_fs_error_t M_fs_info_file(M_fs_info_t **info, M_fs_file_t *fd, unsigned int flags);
const M_fs_perms_t *M_fs_info_get_perms(const M_fs_info_t *info);
void M_fs_info_destroy(M_fs_info_t *info);
void M_fs_file_close(M_fs_file_t *fd);
M_fs_error_t M_fs_file_read(M_fs_file_t *fd, unsigned char *buf, size_t buf_size, size_t *read_len, unsigned int rw_mode);
M_fs_error_t M_fs_file_write(M_fs_file_t *fd, const unsigned char *buf, size_t buf_size, size_t *wrote_len, unsigned int rw_mode);
void M_fs_progress_set_result(M_fs_progress_t *progress, M_fs_error_t res);
void M_fs_progress_set_size_total_progess(M_fs_progress_t *progress, size_t total);
size_t M_fs_progress_get_size_total_progess(const M_fs_progress_t *progress);
void M_fs_progress_set_size_current_progress(M_fs_progress_t *progress, size_t current);
void M_fs_progress_set_count(M_fs_progress_t *progress, size_t count);
size_t M_fs_progress_get_count(const M_fs_progress_t *progress);