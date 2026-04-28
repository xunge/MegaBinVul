#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>

#define STRLEN(s) (sizeof(s)-1)
#define DECIMAL_STR_MAX(type) ((sizeof(type)*8 + 2)/3 + 1)
#define UID_FMT "%u"
#define GID_FMT "%u"
#define UID_INVALID ((uid_t)-1)
#define GID_INVALID ((gid_t)-1)
#define O_PATH 2097152
#define AT_EMPTY_PATH 0x1000
#define LOG_ERR 3
#define LOG_DEBUG 7
#define EMPTY_DIRECTORY 1

typedef struct Item {
    unsigned mode_set:1;
    unsigned uid_set:1;
    unsigned gid_set:1;
    unsigned mask_perms:1;
    int type;
    mode_t mode;
    uid_t uid;
    gid_t gid;
} Item;

#define _cleanup_close_ __attribute__((cleanup(cleanup_close)))

static inline void cleanup_close(int *fd) {
    if (*fd >= 0)
        close(*fd);
}

static inline int safe_close(int fd) {
    if (fd >= 0)
        close(fd);
    return -1;
}

static inline int xsprintf(char *str, const char *format, ...) {
    va_list ap;
    int r;
    va_start(ap, format);
    r = vsprintf(str, format, ap);
    va_end(ap);
    return r;
}

static inline int log_full_errno(int level, int error, const char *format, ...) {
    return -error;
}

static inline int log_error_errno(int error, const char *format, ...) {
    return -error;
}

static inline int log_debug(const char *format, ...) {
    return 0;
}

static inline int label_fix(const char *path, bool b1, bool b2) {
    return 0;
}