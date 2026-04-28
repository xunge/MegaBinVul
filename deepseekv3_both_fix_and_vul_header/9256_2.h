#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>

#define SUCCESS 0
#define FAILURE -1
#define DEFAULT_SLASH '/'
#define MAXPATHLEN 4096
#define PHP_WIN32 0
#define PHP_API_VERSION 20100412
#define PHAR_ENT_PERM_MASK 0777
#define REPORT_ERRORS 0
#define ENFORCE_SAFE_MODE 0
#define PHP_STREAM_MKDIR_RECURSIVE 1
#define TSRMLS_CC
#define TSRMLS_DC

typedef int zend_bool;
typedef unsigned int mode_t;

struct _php_stream;
typedef struct _php_stream php_stream;

typedef struct _phar_entry_info {
    char *filename;
    size_t filename_len;
    zend_bool is_mounted;
    zend_bool is_dir;
    unsigned int flags;
    size_t uncompressed_filesize;
    php_stream *fp;
} phar_entry_info;

typedef struct _php_stream_statbuf {
    struct stat sb;
} php_stream_statbuf;

typedef struct _cwd_state {
    char *cwd;
    size_t cwd_length;
} cwd_state;

int virtual_file_ex(cwd_state *state, const char *path, const char *realpath, int flags TSRMLS_DC);
int php_stream_stat_path(const char *path, php_stream_statbuf *ssb);
int php_stream_mkdir(const char *path, mode_t mode, int options, void *context);
php_stream *php_stream_open_wrapper(const char *path, const char *mode, int options, void *context);
int php_stream_close(php_stream *stream);
php_stream *phar_get_efp(phar_entry_info *entry, int flags TSRMLS_CC);
int phar_open_entry_fp(phar_entry_info *entry, char **error, int flags TSRMLS_CC);
int phar_seek_efp(phar_entry_info *entry, off_t offset, int whence, int flags, int dummy TSRMLS_CC);
int phar_stream_copy_to_stream(php_stream *src, php_stream *dest, size_t len, void *dummy);
int VCWD_CHMOD(const char *path, mode_t mode);
char *estrndup(const char *s, size_t len);
void efree(void *ptr);
int spprintf(char **str, size_t max_len, const char *format, ...);
const char *zend_memrchr(const char *s, int c, size_t len);
int PHAR_OPENBASEDIR_CHECKPATH(const char *path);
#define CWD_EXPAND 1