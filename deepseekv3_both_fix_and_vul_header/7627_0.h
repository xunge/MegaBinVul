#include <stdio.h>
#include <errno.h>
#include <limits.h>

typedef int pj_oshandle_t;
typedef long pj_off_t;
typedef int pj_status_t;

enum pj_file_seek_type {
    PJ_SEEK_SET,
    PJ_SEEK_CUR,
    PJ_SEEK_END
};

#define PJ_MAXLONG LONG_MAX
#define PJ_MINLONG LONG_MIN
#define PJ_ENOTSUP 1
#define PJ_EINVAL 2
#define PJ_SUCCESS 0
#define PJ_RETURN_OS_ERROR(e) (e)

#define pj_assert(expr) ((void)0)
#define PJ_DEF(ret) ret