#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define STRLEN(s) (sizeof(s)-1)
#define DECIMAL_STR_MAX(type) ((sizeof(type)*8 + 2)/3 + 1)
#define HAVE_ACL 1

typedef struct Item {
    int acl_access;
    int acl_default;
    int force;
} Item;

#define ACL_TYPE_ACCESS 0
#define ACL_TYPE_DEFAULT 1
#define O_PATH 2097152
#define AT_EMPTY_PATH 0x1000

#define _cleanup_close_

int log_error_errno(int err, const char *format, ...);
int log_debug(const char *format, ...);
int log_debug_errno(int err, const char *format, ...);
int path_set_acl(const char *fn, const char *path, int type, int acl, int force);
int xsprintf(char *str, const char *format, ...);