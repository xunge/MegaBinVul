#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <errno.h>

#define MAXPATHLEN 4096
#define FAILURE -1
#define O_BINARY 0
#define E_WARNING 2
#define PHP_WIN32 0
#define FD_CLOEXEC 1
#define LOCK_EX 2
#define TSRMLS_DC
#define TSRMLS_CC
#define PG(open_basedir) (0)

typedef struct _ps_files {
    int fd;
    char *lastkey;
    int filemode;
} ps_files;

typedef struct {
    int invalid_session_id;
} ps_globals;

ps_globals PS = {0};

#define PS(var) (PS.var)

int php_session_valid_key(const char *key);
int php_check_open_basedir(const char *path TSRMLS_DC);
void php_error_docref(const char *ref TSRMLS_CC, int level, const char *format, ...);
void ps_files_close(ps_files *data);
int ps_files_path_create(char *buf, size_t buflen, ps_files *data, const char *key);
char *estrdup(const char *s);
void efree(void *ptr);
int ps_files_valid_key(const char *key);
#define VCWD_OPEN_MODE(path, flags, mode) open(path, flags, mode)