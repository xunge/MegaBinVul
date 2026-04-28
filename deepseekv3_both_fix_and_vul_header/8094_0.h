#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>

#define CWD_API
#define MAXPATHLEN 4096
#define DEFAULT_SLASH '/'
#define TSRMLS_DC
#define TSRMLS_CC
#define TSRM_WIN32
#define VIRTUAL_CWD_DEBUG 0
#define CWD_REALPATH 0
#define IS_ABSOLUTE_PATH(p, l) (IS_SLASH((p)[0]))
#define IS_SLASH(c) ((c) == '/' || (c) == '\\')
#define IS_UNC_PATH(p, l) ((l) > 2 && IS_SLASH((p)[0]) && IS_SLASH((p)[1]) && !IS_SLASH((p)[2]))
#define CWDG(v) (0)

typedef struct _cwd_state {
    char *cwd;
    int cwd_length;
} cwd_state;

typedef int (*verify_path_func)(cwd_state *state);

#define CWD_STATE_COPY(d, s) \
    do { \
        (d)->cwd_length = (s)->cwd_length; \
        (d)->cwd = malloc((s)->cwd_length + 1); \
        if ((d)->cwd) { \
            memcpy((d)->cwd, (s)->cwd, (s)->cwd_length + 1); \
        } \
    } while (0)

#define CWD_STATE_FREE(s) \
    do { \
        if ((s)->cwd) { \
            free((s)->cwd); \
            (s)->cwd = NULL; \
        } \
    } while (0)

extern int tsrm_realpath_r(char *path, int start, int path_length, int *ll, time_t *t, int use_realpath, int is_dir, void *ptr TSRMLS_DC);