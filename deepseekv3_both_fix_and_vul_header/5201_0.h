#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct _php_stream_wrapper php_stream_wrapper;
typedef struct _php_stream_context php_stream_context;

#define PHP_WIN32
#define ERROR_INVALID_NAME 123
#define EXDEV 18
#define EPERM 1
#define E_WARNING 2
#define SUCCESS 0
#define TSRM_WIN32
#define NETWARE

typedef struct stat zend_stat_t;

int php_win32_check_trailing_space(const char *path, int len);
void php_win32_docref2_from_error(int error, const char *from, const char *to);
int php_check_open_basedir(const char *path);
int VCWD_RENAME(const char *from, const char *to);
int php_copy_file(const char *from, const char *to);
int VCWD_STAT(const char *path, zend_stat_t *buf);
int VCWD_CHMOD(const char *path, mode_t mode);
int VCWD_CHOWN(const char *path, uid_t owner, gid_t group);
int VCWD_UNLINK(const char *path);
void php_error_docref2(const char *docref, const char *param1, const char *param2, int type, const char *format, ...);
void php_clear_stat_cache(int clear_realpath_cache, const char *filename, int filename_len);